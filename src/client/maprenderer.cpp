/*
 * Copyright (C) 2016 necropotame (necropotame@gmail.com)
 * 
 * This file is part of TeeUniverses.
 * 
 * TeeUniverses is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * TeeUniverses is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with TeeUniverses.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <client/components/graphics.h>
#include <client/components/assetsrenderer.h>
#include <shared/components/assetsmanager.h>

#include "maprenderer.h"

CMapRenderer::CMapRenderer(CClientKernel* pKernel) :
	CClientKernel::CGuest(pKernel)
{
	
}
	
void CMapRenderer::SetCanvas(const gui::CRect& Canvas, vec2 ScreenPos)
{
	m_ScreenPos = ScreenPos;
	m_Canvas = Canvas;
}

void CMapRenderer::SetCamera(vec2 CameraPos, float CameraZoom)
{
	m_CameraPos = CameraPos;
	m_CameraZoom = CameraZoom;
	
	m_GroupCameraPos = (m_CameraPos * m_GroupHardParallax) + m_GroupPos;
}

void CMapRenderer::SetGroup(CAssetPath GroupPath)
{
	const CAsset_MapGroup* pGroup = AssetsManager()->GetAsset<CAsset_MapGroup>(GroupPath);
	if(pGroup)
	{
		m_GroupPos = pGroup->GetPosition();
		m_GroupHardParallax = pGroup->GetHardParallax();
	
		m_GroupCameraPos = (m_CameraPos * m_GroupHardParallax) + m_GroupPos;
	}
	else
		UnsetGroup();
}

void CMapRenderer::UnsetGroup()
{
	m_GroupPos = vec2(0.0f, 0.0f);
	m_GroupHardParallax = vec2(1.0f, 1.0f);
	
	m_GroupCameraPos = (m_CameraPos * m_GroupHardParallax) + m_GroupPos;
}

vec2 CMapRenderer::MapPosToScreenPos(vec2 MapPos) const
{
	return m_ScreenPos + (MapPos - m_GroupCameraPos)*m_CameraZoom;
}

vec2 CMapRenderer::ScreenPosToMapPos(vec2 ScreenPos) const
{
	return m_GroupCameraPos + (ScreenPos - m_ScreenPos)/m_CameraZoom;
}

vec2 CMapRenderer::MapPosToTilePos(vec2 MapPos) const
{
	return MapPos/32.0f;
}

vec2 CMapRenderer::TilePosToMapPos(vec2 TilePos) const
{
	return TilePos*32.0f;
}

vec2 CMapRenderer::ScreenPosToTilePos(vec2 ScreenPos) const
{
	return MapPosToTilePos(ScreenPosToMapPos(ScreenPos));
}

vec2 CMapRenderer::TilePosToScreenPos(vec2 TilePos) const
{
	return MapPosToScreenPos(TilePosToMapPos(TilePos));
}

void CMapRenderer::RenderGrid(int Width, int Height, float Scale)
{
	Graphics()->TextureClear();
	Graphics()->LinesBegin();
	Graphics()->SetColor(0.5f, 0.5f, 0.5f, 0.5f);
	
	vec2 minCorner = MapPosToScreenPos(vec2(0.0f, 0.0f));
	vec2 maxCorner = MapPosToScreenPos(vec2(Width*Scale, Height*Scale));
	vec2 size = maxCorner - minCorner;
	
	{
		CGraphics::CLineItem Lines[4];
		Lines[0] = CGraphics::CLineItem(minCorner.x, minCorner.y, maxCorner.x, minCorner.y);
		Lines[1] = CGraphics::CLineItem(maxCorner.x, minCorner.y, maxCorner.x, maxCorner.y);
		Lines[2] = CGraphics::CLineItem(maxCorner.x, maxCorner.y, minCorner.x, maxCorner.y);
		Lines[3] = CGraphics::CLineItem(minCorner.x, maxCorner.y, minCorner.x, minCorner.y);
		
		Graphics()->LinesDraw(Lines, 4);
	}

	//Draw tile layer
	vec2 MinTilePos = ScreenPosToTilePos(vec2(GetCanvas().x, GetCanvas().y));
	vec2 MaxTilePos = ScreenPosToTilePos(vec2(GetCanvas().x + GetCanvas().w, GetCanvas().y + GetCanvas().h));
	int MinX = clamp((int) MinTilePos.x, 0, Width-1);
	int MaxX = clamp((int) MaxTilePos.x+1, 0, Width-1);
	int MinY = clamp((int) MinTilePos.y, 0, Height-1);
	int MaxY = clamp((int) MaxTilePos.y+1, 0, Height-1);
	
	Graphics()->SetColor(0.25f, 0.25f, 0.25f, 0.25f);
	for(int j=MinY; j<=MaxY; j++)
	{
		float y = minCorner.y+size.y*(static_cast<float>(j)/Height);
		CGraphics::CLineItem Line(minCorner.x, y, maxCorner.x, y);
		Graphics()->LinesDraw(&Line, 1);
	}
	for(int i=MinX; i<=MaxX; i++)
	{
		float x = minCorner.x+size.x*(static_cast<float>(i)/Width);
		CGraphics::CLineItem Line(x, minCorner.y, x, maxCorner.y);
		Graphics()->LinesDraw(&Line, 1);
	}
	
	Graphics()->LinesEnd();
}

void CMapRenderer::RenderGrid_LayerTiles(CAssetPath LayerPath)
{
	if(LayerPath.GetType() == CAsset_MapLayerTiles::TypeId)
	{
		const CAsset_MapLayerTiles* pLayer = AssetsManager()->GetAsset<CAsset_MapLayerTiles>(LayerPath);
		if(!pLayer)
			return;
		
		RenderGrid(pLayer->GetTileWidth(), pLayer->GetTileHeight(), 32.0f);
	}
	else if(LayerPath.GetType() == CAsset_MapZoneTiles::TypeId)
	{
		const CAsset_MapZoneTiles* pLayer = AssetsManager()->GetAsset<CAsset_MapZoneTiles>(LayerPath);
		if(!pLayer)
			return;
		
		RenderGrid(pLayer->GetTileWidth(), pLayer->GetTileHeight(), 32.0f);
	}
}

template<class TILE>
void RenderTiles_Zone_Impl(CMapRenderer* pMapRenderer, CAssetPath ZoneTypePath, const array2d<TILE, allocator_copy<TILE> >& Tiles, vec2 Pos, CAssetPath ZoneTexture)
{
	const CAsset_ZoneType* pZoneType = pMapRenderer->AssetsManager()->GetAsset<CAsset_ZoneType>(ZoneTypePath);
	
	pMapRenderer->AssetsRenderer()->TextureSet(ZoneTexture);
	pMapRenderer->Graphics()->QuadsBegin();

	float TileSize = 32.0f*pMapRenderer->m_CameraZoom;

	//Draw tile layer
	vec2 MinTilePos = pMapRenderer->ScreenPosToTilePos(vec2(pMapRenderer->GetCanvas().x, pMapRenderer->GetCanvas().y));
	vec2 MaxTilePos = pMapRenderer->ScreenPosToTilePos(vec2(pMapRenderer->GetCanvas().x + pMapRenderer->GetCanvas().w, pMapRenderer->GetCanvas().y + pMapRenderer->GetCanvas().h));
	int MinX = MinTilePos.x-1;
	int MaxX = MaxTilePos.x+1;
	int MinY = MinTilePos.y-1;
	int MaxY = MaxTilePos.y+1;
	
	for(int j=MinY; j<MaxY; j++)
	{
		for(int i=MinX; i<=MaxX; i++)
		{
			const TILE& Tile = Tiles.get_clamp(i, j);
			
			if(Tile.GetIndex() < 1)
				continue;
			
			bool IndexFound = false;
			vec4 Color = 1.0f;
			if(pZoneType)
			{
				CSubPath IndexPath;
				CAsset_ZoneType::CIteratorIndex Iter;
				for(Iter = pZoneType->BeginIndex(); Iter != pZoneType->EndIndex(); ++Iter)
				{
					if(pZoneType->GetIndexNumber(*Iter) == Tile.GetIndex())
					{
						Color = pZoneType->GetIndexColor(*Iter);
						IndexFound = true;
						break;
					}
				}
			}
			
			if(!IndexFound)
				continue;
			
			Color.a *= 0.5f;
			pMapRenderer->Graphics()->SetColor(Color, true);
			
			vec2 TilePos = pMapRenderer->MapPosToScreenPos(Pos + vec2(i*32.0f, j*32.0f));
			
			float Shift = fmod(pMapRenderer->m_LocalTime/4.0f, 1.0f);
			int Size = 8;
			
			float x0 = ((i%Size))/static_cast<float>(Size) + Shift;
			float y0 = ((j%Size))/static_cast<float>(Size) + Shift;
			float x2 = x0 + 1.0f/static_cast<float>(Size);
			float y2 = y0 + 1.0f/static_cast<float>(Size);
			float x1 = x2;
			float y1 = y0;
			float x3 = x0;
			float y3 = y2;
			
			pMapRenderer->Graphics()->QuadsSetSubsetFree(x0, y0, x1, y1, x2, y2, x3, y3);
			CGraphics::CQuadItem QuadItem(TilePos.x, TilePos.y, TileSize, TileSize);
			pMapRenderer->Graphics()->QuadsDrawTL(&QuadItem, 1);
		}
	}
	pMapRenderer->Graphics()->QuadsEnd();
	
	pMapRenderer->Graphics()->TextureClear();
	pMapRenderer->Graphics()->QuadsBegin();
	
	//Draw border
	for(int j=MinY; j<MaxY; j++)
	{
		for(int i=MinX; i<=MaxX; i++)
		{
			const TILE& Tile = Tiles.get_clamp(i, j);
			
			if(Tile.GetIndex() < 1)
				continue;
				
			bool IndexFound = false;
			vec4 Color = 1.0f;
			if(pZoneType)
			{
				CSubPath IndexPath;
				CAsset_ZoneType::CIteratorIndex Iter;
				for(Iter = pZoneType->BeginIndex(); Iter != pZoneType->EndIndex(); ++Iter)
				{
					if(pZoneType->GetIndexNumber(*Iter) == Tile.GetIndex())
					{
						Color = pZoneType->GetIndexColor(*Iter);
						IndexFound = true;
						break;
					}
				}
			}
			
			if(!IndexFound)
				continue;
			
			pMapRenderer->Graphics()->SetColor(Color, true);
			
			vec2 TilePos = pMapRenderer->MapPosToScreenPos(Pos + vec2(i*32.0f, j*32.0f));
			
			bool AirL = (Tiles.get_clamp(i-1, j).GetIndex() != Tile.GetIndex());
			bool AirR = (Tiles.get_clamp(i+1, j).GetIndex() != Tile.GetIndex());
			bool AirT = (Tiles.get_clamp(i, j-1).GetIndex() != Tile.GetIndex());
			bool AirB = (Tiles.get_clamp(i, j+1).GetIndex() != Tile.GetIndex());
			
			bool AirTL = (Tiles.get_clamp(i-1, j-1).GetIndex() != Tile.GetIndex());
			bool AirTR = (Tiles.get_clamp(i+1, j-1).GetIndex() != Tile.GetIndex());
			bool AirBL = (Tiles.get_clamp(i-1, j+1).GetIndex() != Tile.GetIndex());
			bool AirBR = (Tiles.get_clamp(i+1, j+1).GetIndex() != Tile.GetIndex());
			
			if(AirT)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x, TilePos.y,
					TilePos.x + TileSize, TilePos.y,
					TilePos.x + (AirL ? TileSize/4.0f : 0.0f), TilePos.y+TileSize/4.0f,
					TilePos.x + TileSize - (AirR ? TileSize/4.0f : 0.0f), TilePos.y+TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(AirB)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x, TilePos.y+TileSize,
					TilePos.x+TileSize, TilePos.y+TileSize,
					TilePos.x+(AirL ? TileSize/4.0f : 0.0f), TilePos.y+TileSize-TileSize/4.0f,
					TilePos.x+TileSize-(AirR ? TileSize/4.0f : 0.0f), TilePos.y+TileSize-TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(AirL)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x, TilePos.y,
					TilePos.x, TilePos.y + TileSize,
					TilePos.x+TileSize/4.0f, TilePos.y+(AirT ? TileSize/4.0f : 0.0f),
					TilePos.x+TileSize/4.0f, TilePos.y+TileSize-(AirB ? TileSize/4.0f : 0.0f)
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(AirR)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x+TileSize, TilePos.y,
					TilePos.x+TileSize, TilePos.y+TileSize,
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y+(AirT ? TileSize/4.0f : 0.0f),
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y+TileSize-(AirB ? TileSize/4.0f : 0.0f)
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			
			if(!AirT && !AirL && AirTL)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x, TilePos.y,
					TilePos.x+TileSize/4.0f, TilePos.y,
					TilePos.x, TilePos.y+TileSize/4.0f,
					TilePos.x+TileSize/4.0f, TilePos.y+TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(!AirT && !AirR && AirTR)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x+TileSize, TilePos.y,
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y,
					TilePos.x+TileSize, TilePos.y+TileSize/4.0f,
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y+TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(!AirB && !AirL && AirBL)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x, TilePos.y+TileSize,
					TilePos.x+TileSize/4.0f, TilePos.y+TileSize,
					TilePos.x, TilePos.y+TileSize-TileSize/4.0f,
					TilePos.x+TileSize/4.0f, TilePos.y+TileSize-TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
			if(!AirB && !AirR && AirBR)
			{
				CGraphics::CFreeformItem Freeform(
					TilePos.x+TileSize, TilePos.y+TileSize,
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y+TileSize,
					TilePos.x+TileSize, TilePos.y+TileSize-TileSize/4.0f,
					TilePos.x+TileSize-TileSize/4.0f, TilePos.y+TileSize-TileSize/4.0f
				);
				pMapRenderer->Graphics()->QuadsDrawFreeform(&Freeform, 1);
			}
		}
	}
	
	pMapRenderer->Graphics()->QuadsEnd();
}

void CMapRenderer::RenderTiles_Zone(CAssetPath ZoneTypePath, const array2d<CAsset_MapLayerTiles::CTile, allocator_copy<CAsset_MapLayerTiles::CTile> >& Tiles, vec2 Pos, CAssetPath ZoneTexture)
{
	RenderTiles_Zone_Impl(this, ZoneTypePath, Tiles, Pos, ZoneTexture);
}

void CMapRenderer::RenderTiles_Zone(CAssetPath ZoneTypePath, const array2d<CAsset_MapZoneTiles::CTile, allocator_copy<CAsset_MapZoneTiles::CTile> >& Tiles, vec2 Pos, CAssetPath ZoneTexture)
{
	RenderTiles_Zone_Impl(this, ZoneTypePath, Tiles, Pos, ZoneTexture);
}

void CMapRenderer::RenderTiles_Image(const array2d<CAsset_MapLayerTiles::CTile, allocator_copy<CAsset_MapLayerTiles::CTile> >& Tiles, vec2 Pos, CAssetPath ImagePath, vec4 Color)
{
	AssetsRenderer()->TextureSet(ImagePath);
	
	Graphics()->QuadsBegin();
	Graphics()->SetColor(Color, true);

	//Draw tile layer
	vec2 MinTilePos = ScreenPosToTilePos(vec2(GetCanvas().x, GetCanvas().y));
	vec2 MaxTilePos = ScreenPosToTilePos(vec2(GetCanvas().x + GetCanvas().w, GetCanvas().y + GetCanvas().h));
	int MinX = MinTilePos.x-1;
	int MaxX = MaxTilePos.x+1;
	int MinY = MinTilePos.y-1;
	int MaxY = MaxTilePos.y+1;
	
	for(int j=MinY; j<MaxY; j++)
	{
		for(int i=MinX; i<=MaxX; i++)
		{
			const CAsset_MapLayerTiles::CTile& Tile = Tiles.get_clamp(i, j);
			
			int Index = Tile.GetIndex();
			if(Index)
			{
				vec2 TilePos = MapPosToScreenPos(Pos + vec2(i*32.0f, j*32.0f));
				
				float x0 = 0;
				float y0 = 0;
				float x1 = 1;
				float y1 = 0;
				float x2 = 1;
				float y2 = 1;
				float x3 = 0;
				float y3 = 1;

				if(Tile.GetFlags()&CAsset_MapLayerTiles::TILEFLAG_VFLIP)
				{
					x0 = x2;
					x1 = x3;
					x2 = x3;
					x3 = x0;
				}

				if(Tile.GetFlags()&CAsset_MapLayerTiles::TILEFLAG_HFLIP)
				{
					y0 = y3;
					y2 = y1;
					y3 = y1;
					y1 = y0;
				}

				if(Tile.GetFlags()&CAsset_MapLayerTiles::TILEFLAG_ROTATE)
				{
					float Tmp = x0;
					x0 = x3;
					x3 = x2;
					x2 = x1;
					x1 = Tmp;
					Tmp = y0;
					y0 = y3;
					y3 = y2;
					y2 = y1;
					y1 = Tmp;
				}
				
				Graphics()->QuadsSetSubsetFree(x0, y0, x1, y1, x2, y2, x3, y3, Index);
				CGraphics::CQuadItem QuadItem(TilePos.x, TilePos.y, 32.0f*m_CameraZoom, 32.0f*m_CameraZoom);
				Graphics()->QuadsDrawTL(&QuadItem, 1);
			}
		}
	}
	
	Graphics()->QuadsEnd();
}

void CMapRenderer::RenderQuads(const CAsset_MapLayerQuads::CQuad* pQuads, int NbQuads, vec2 LayerPos, CAssetPath ImagePath, vec4 LayerColor)
{
	AssetsRenderer()->TextureSet(ImagePath);
	
	Graphics()->QuadsBegin();
	
	for(int i=0; i<NbQuads; i++)
	{
		const CAsset_MapLayerQuads::CQuad* pQuad = &pQuads[i];
				
		vec2 Position;
		matrix2x2 Transform;
		vec4 Color;
		int DrawState;
		pQuad->GetTransform(AssetsManager(), m_Time, &Transform, &Position);
		pQuad->GetDrawState(AssetsManager(), m_Time, &Color, &DrawState);
		
		if(DrawState == CAsset_SkeletonAnimation::LAYERSTATE_HIDDEN)
			continue;
		
		Position += LayerPos;
		Color *= LayerColor;
		
		//Color
		Graphics()->SetColor4(pQuad->GetColor0()*Color, pQuad->GetColor1()*Color, pQuad->GetColor2()*Color, pQuad->GetColor3()*Color, true);
		
		//UVs
		bool RepeatU = false;
		bool RepeatV = false;
		
		if(pQuad->GetUV0().x < 0.0f || pQuad->GetUV0().x > 1.0f)
			RepeatU = true;
		if(pQuad->GetUV0().y < 0.0f || pQuad->GetUV0().y > 1.0f)
			RepeatV = true;
		if(pQuad->GetUV1().x < 0.0f || pQuad->GetUV1().x > 1.0f)
			RepeatU = true;
		if(pQuad->GetUV1().y < 0.0f || pQuad->GetUV1().y > 1.0f)
			RepeatV = true;
		if(pQuad->GetUV2().x < 0.0f || pQuad->GetUV2().x > 1.0f)
			RepeatU = true;
		if(pQuad->GetUV2().y < 0.0f || pQuad->GetUV2().y > 1.0f)
			RepeatV = true;
		if(pQuad->GetUV3().x < 0.0f || pQuad->GetUV3().x > 1.0f)
			RepeatU = true;
		if(pQuad->GetUV3().y < 0.0f || pQuad->GetUV3().y > 1.0f)
			RepeatV = true;
		
		Graphics()->WrapMode(
			RepeatU ? CGraphics::WRAP_REPEAT : CGraphics::WRAP_CLAMP,
			RepeatV ? CGraphics::WRAP_REPEAT : CGraphics::WRAP_CLAMP);
		
		Graphics()->QuadsSetSubsetFree(
			pQuad->GetUV0().x, pQuad->GetUV0().y,
			pQuad->GetUV1().x, pQuad->GetUV1().y,
			pQuad->GetUV2().x, pQuad->GetUV2().y,
			pQuad->GetUV3().x, pQuad->GetUV3().y
		);
		
		//Vertices
		
		vec2 Vertices[4];
		{
			vec2 TestBefore = pQuad->GetVertex0();
			vec2 TestAfter = Transform*pQuad->GetVertex0() + Position;
			Vertices[0] = MapPosToScreenPos(Transform*pQuad->GetVertex0() + Position);
		}
		{
			vec2 TestBefore = pQuad->GetVertex1();
			vec2 TestAfter = Transform*pQuad->GetVertex1() + Position;
			Vertices[1] = MapPosToScreenPos(Transform*pQuad->GetVertex1() + Position);
		}
		{
			vec2 TestBefore = pQuad->GetVertex2();
			vec2 TestAfter = Transform*pQuad->GetVertex2() + Position;
			Vertices[2] = MapPosToScreenPos(Transform*pQuad->GetVertex2() + Position);
		}
		{
			vec2 TestBefore = pQuad->GetVertex3();
			vec2 TestAfter = Transform*pQuad->GetVertex3() + Position;
			Vertices[3] = MapPosToScreenPos(Transform*pQuad->GetVertex3() + Position);
		}

		CGraphics::CFreeformItem Freeform(
			Vertices[0].x, Vertices[0].y,
			Vertices[1].x, Vertices[1].y,
			Vertices[2].x, Vertices[2].y,
			Vertices[3].x, Vertices[3].y
		);
		Graphics()->QuadsDrawFreeform(&Freeform, 1);
		
	}
	
	Graphics()->QuadsEnd();
	Graphics()->WrapNormal();
}

void CMapRenderer::RenderQuads_Mesh(const CAsset_MapLayerQuads::CQuad* pQuads, int NbQuads)
{
	Graphics()->TextureClear();
	Graphics()->LinesBegin();
	
	for(int i=0; i<NbQuads; i++)
	{
		const CAsset_MapLayerQuads::CQuad* pQuad = &pQuads[i];
		
		vec4 Color = 1.0f;
		
		vec2 Position;
		matrix2x2 Transform;
		pQuad->GetTransform(AssetsManager(), m_Time, &Transform, &Position);
		
		//Vertices
		{
			{
				vec2 Vertex0Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex0() + Position);
				vec2 Vertex1Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex1() + Position);
				
				Graphics()->SetColor2(pQuads[i].GetColor0(), pQuads[i].GetColor1(), true);
				
				CGraphics::CLineItem Line(Vertex0Pos.x, Vertex0Pos.y, Vertex1Pos.x, Vertex1Pos.y);
				Graphics()->LinesDraw(&Line, 1);
			}
			{
				vec2 Vertex0Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex1() + Position);
				vec2 Vertex1Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex3() + Position);
				
				Graphics()->SetColor2(pQuads[i].GetColor1(), pQuads[i].GetColor3(), true);
				
				CGraphics::CLineItem Line(Vertex0Pos.x, Vertex0Pos.y, Vertex1Pos.x, Vertex1Pos.y);
				Graphics()->LinesDraw(&Line, 1);
			}
			{
				vec2 Vertex0Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex3() + Position);
				vec2 Vertex1Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex2() + Position);
				
				Graphics()->SetColor2(pQuads[i].GetColor3(), pQuads[i].GetColor2(), true);
				
				CGraphics::CLineItem Line(Vertex0Pos.x, Vertex0Pos.y, Vertex1Pos.x, Vertex1Pos.y);
				Graphics()->LinesDraw(&Line, 1);
			}
			{
				vec2 Vertex0Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex2() + Position);
				vec2 Vertex1Pos = MapPosToScreenPos(Transform * pQuads[i].GetVertex0() + Position);
				
				Graphics()->SetColor2(pQuads[i].GetColor2(), pQuads[i].GetColor0(), true);
				
				CGraphics::CLineItem Line(Vertex0Pos.x, Vertex0Pos.y, Vertex1Pos.x, Vertex1Pos.y);
				Graphics()->LinesDraw(&Line, 1);
			}
		}
	}
	
	Graphics()->LinesEnd();
}

void CMapRenderer::RenderGroup(CAssetPath GroupPath)
{
	const CAsset_MapGroup* pGroup = AssetsManager()->GetAsset<CAsset_MapGroup>(GroupPath);
	if(!pGroup)
		return;
	
	const CAssetState* pState = AssetsManager()->GetAssetState(GroupPath);
	if(pState && !pState->m_Visible)
		return;
	
	SetGroup(GroupPath);
	
	CAsset_MapGroup::CIteratorLayer IterLayer;
	for(IterLayer = pGroup->BeginLayer(); IterLayer != pGroup->EndLayer(); ++IterLayer)
	{
		CAssetPath LayerPath = pGroup->GetLayer(*IterLayer);
			
		const CAssetState* pState = AssetsManager()->GetAssetState(LayerPath);
		if(pState && !pState->m_Visible)
			continue;
			
		if(LayerPath.GetType() == CAsset_MapLayerTiles::TypeId)
		{
			const CAsset_MapLayerTiles* pLayer = AssetsManager()->GetAsset<CAsset_MapLayerTiles>(LayerPath);
			if(!pLayer)
				continue;
			
			RenderTiles_Image(pLayer->GetTileArray(), vec2(0.0f, 0.0f), pLayer->GetImagePath(), pLayer->GetColor());
		}
		else if(LayerPath.GetType() == CAsset_MapLayerQuads::TypeId)
		{
			const CAsset_MapLayerQuads* pLayer = AssetsManager()->GetAsset<CAsset_MapLayerQuads>(LayerPath);
			if(!pLayer)
				continue;
			
			RenderQuads(pLayer->GetQuadPtr(), pLayer->GetQuadArraySize(), vec2(0.0f, 0.0f), pLayer->GetImagePath(), vec4(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

void CMapRenderer::RenderMap(CAssetPath MapPath)
{
	const CAsset_Map* pMap = AssetsManager()->GetAsset<CAsset_Map>(MapPath);
	if(!pMap)
		return;
	
	const CAssetState* pState = AssetsManager()->GetAssetState(MapPath);
	if(pState && !pState->m_Visible)
		return;
	
	{
		CAsset_Map::CIteratorBgGroup Iter;
		for(Iter = pMap->BeginBgGroup(); Iter != pMap->EndBgGroup(); ++Iter)
		{
			RenderGroup(pMap->GetBgGroup(*Iter));
		}
	}
	{
		CAsset_Map::CIteratorFgGroup Iter;
		for(Iter = pMap->BeginFgGroup(); Iter != pMap->EndFgGroup(); ++Iter)
		{
			RenderGroup(pMap->GetFgGroup(*Iter));
		}
	}
		
	UnsetGroup();
}

void CMapRenderer::RenderMap_Zones(CAssetPath MapPath, CAssetPath ZoneTexture)
{
	const CAsset_Map* pMap = AssetsManager()->GetAsset<CAsset_Map>(MapPath);
	if(!pMap)
		return;
	
	const CAssetState* pState = AssetsManager()->GetAssetState(MapPath);
	if(pState && !pState->m_Visible)
		return;
	
	CAsset_Map::CIteratorZoneLayer Iter;
	for(Iter = pMap->BeginZoneLayer(); Iter != pMap->EndZoneLayer(); ++Iter)
	{
		CAssetPath ZonePath = pMap->GetZoneLayer(*Iter);
		const CAsset_MapZoneTiles* pZone = AssetsManager()->GetAsset<CAsset_MapZoneTiles>(ZonePath);
		if(!pZone)
			continue;
	
		const CAssetState* pState = AssetsManager()->GetAssetState(ZonePath);
		if(pState && !pState->m_Visible)
			continue;
		
		RenderTiles_Zone(pZone->GetZoneTypePath(), pZone->GetTileArray(), 0.0f, ZoneTexture);
	}
}