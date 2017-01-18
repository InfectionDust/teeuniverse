/*
 * Copyright (C) 2016 necropotame (necropotame@gmail.com)
 * 
 * This file is part of TeeUniverse.
 * 
 * TeeUniverse is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * TeeUniverse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with TeeUniverse.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * THIS FILE HAS BEEN GENERATED BY A SCRIPT.
 * DO NOT EDIT MANUALLY!
 *
 * Please use the script "scripts/assets/assets.py" to regenerate it.
 *
 * Why this file is generated by a script?
 * Because there is more than 10 files that follow the same format.
 * In addition, each time a new member is added, enums, getter, setters,
 * copy/transfert functions and storage structure must be updated.
 * It's too much to avoid mistakes.
 */

#include <generated/assets/maplayertiles.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_MapLayerTiles::CTile::CTile()
{
	m_Index = 0;
	m_Flags = 0x0;
}

CAsset_MapLayerTiles::CAsset_MapLayerTiles()
{
	m_Color = 1.0f;
	m_Visibility = true;
	m_PositionX = 0;
	m_PositionY = 0;
}

void CAsset_MapLayerTiles::CTile::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapLayerTiles::CTile& SysType)
{
	SysType.m_Index = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Index);
	SysType.m_Flags = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Flags);
}


void CAsset_MapLayerTiles::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapLayerTiles& SysType)
{
	CAsset::CTuaType_0_1_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	{
		const CAsset_MapLayerTiles::CTile::CTuaType_0_1_0* pData = (const CAsset_MapLayerTiles::CTile::CTuaType_0_1_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Tile.m_Data);
		uint32 Width = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Width);
		uint32 Height = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Height);
		uint32 Depth = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Depth);
		SysType.m_Tile.resize(Width, Height, Depth);
		int Size = Width * Height * Depth;
		for(int i=0; i<Size; i++)
		{
			CTile ReadedValue;
			CAsset_MapLayerTiles::CTile::CTuaType_0_1_0::Read(pLoadingContext, pData[i], ReadedValue);
			SysType.m_Tile.linear_set_clamp(i, ReadedValue);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapLayerTiles::CTile::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles::CTile& SysType, CTuaType_0_1_0& TuaType)
{
	TuaType.m_Index = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Index);
	TuaType.m_Flags = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Flags);
}

void CAsset_MapLayerTiles::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles& SysType, CTuaType_0_1_0& TuaType)
{
	CAsset::CTuaType_0_1_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	{
		TuaType.m_Tile.m_Width = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_width());
		TuaType.m_Tile.m_Height = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_height());
		TuaType.m_Tile.m_Depth = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_depth());
		CAsset_MapLayerTiles::CTile::CTuaType_0_1_0* pData = new CAsset_MapLayerTiles::CTile::CTuaType_0_1_0[SysType.m_Tile.get_linear_size()];
		for(int i=0; i<SysType.m_Tile.get_linear_size(); i++)
		{
			CAsset_MapLayerTiles::CTile::CTuaType_0_1_0::Write(pLoadingContext, SysType.m_Tile.linear_get_clamp(i), pData[i]);
		}
		TuaType.m_Tile.m_Data = pLoadingContext->ArchiveFile()->AddData((tua_uint8*) pData, sizeof(CAsset_MapLayerTiles::CTile::CTuaType_0_1_0)*SysType.m_Tile.get_linear_size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

void CAsset_MapLayerTiles::CTile::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapLayerTiles::CTile& SysType)
{
	SysType.m_Index = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Index);
	SysType.m_Flags = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Flags);
}


void CAsset_MapLayerTiles::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapLayerTiles& SysType)
{
	CAsset::CTuaType_0_2_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	{
		const CAsset_MapLayerTiles::CTile::CTuaType_0_2_0* pData = (const CAsset_MapLayerTiles::CTile::CTuaType_0_2_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Tile.m_Data);
		uint32 Width = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Width);
		uint32 Height = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Height);
		uint32 Depth = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Depth);
		SysType.m_Tile.resize(Width, Height, Depth);
		int Size = Width * Height * Depth;
		for(int i=0; i<Size; i++)
		{
			CTile ReadedValue;
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_0::Read(pLoadingContext, pData[i], ReadedValue);
			SysType.m_Tile.linear_set_clamp(i, ReadedValue);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapLayerTiles::CTile::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles::CTile& SysType, CTuaType_0_2_0& TuaType)
{
	TuaType.m_Index = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Index);
	TuaType.m_Flags = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Flags);
}

void CAsset_MapLayerTiles::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles& SysType, CTuaType_0_2_0& TuaType)
{
	CAsset::CTuaType_0_2_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	{
		TuaType.m_Tile.m_Width = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_width());
		TuaType.m_Tile.m_Height = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_height());
		TuaType.m_Tile.m_Depth = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_depth());
		CAsset_MapLayerTiles::CTile::CTuaType_0_2_0* pData = new CAsset_MapLayerTiles::CTile::CTuaType_0_2_0[SysType.m_Tile.get_linear_size()];
		for(int i=0; i<SysType.m_Tile.get_linear_size(); i++)
		{
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_0::Write(pLoadingContext, SysType.m_Tile.linear_get_clamp(i), pData[i]);
		}
		TuaType.m_Tile.m_Data = pLoadingContext->ArchiveFile()->AddData((tua_uint8*) pData, sizeof(CAsset_MapLayerTiles::CTile::CTuaType_0_2_0)*SysType.m_Tile.get_linear_size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

void CAsset_MapLayerTiles::CTile::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapLayerTiles::CTile& SysType)
{
	SysType.m_Index = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Index);
	SysType.m_Flags = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Flags);
}


void CAsset_MapLayerTiles::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapLayerTiles& SysType)
{
	CAsset::CTuaType_0_2_1::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	{
		const CAsset_MapLayerTiles::CTile::CTuaType_0_2_1* pData = (const CAsset_MapLayerTiles::CTile::CTuaType_0_2_1*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Tile.m_Data);
		uint32 Width = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Width);
		uint32 Height = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Height);
		uint32 Depth = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Depth);
		SysType.m_Tile.resize(Width, Height, Depth);
		int Size = Width * Height * Depth;
		for(int i=0; i<Size; i++)
		{
			CTile ReadedValue;
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_1::Read(pLoadingContext, pData[i], ReadedValue);
			SysType.m_Tile.linear_set_clamp(i, ReadedValue);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
	SysType.m_PositionX = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_PositionX);
	SysType.m_PositionY = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_PositionY);
}


void CAsset_MapLayerTiles::CTile::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles::CTile& SysType, CTuaType_0_2_1& TuaType)
{
	TuaType.m_Index = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Index);
	TuaType.m_Flags = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Flags);
}

void CAsset_MapLayerTiles::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles& SysType, CTuaType_0_2_1& TuaType)
{
	CAsset::CTuaType_0_2_1::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	{
		TuaType.m_Tile.m_Width = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_width());
		TuaType.m_Tile.m_Height = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_height());
		TuaType.m_Tile.m_Depth = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_depth());
		CAsset_MapLayerTiles::CTile::CTuaType_0_2_1* pData = new CAsset_MapLayerTiles::CTile::CTuaType_0_2_1[SysType.m_Tile.get_linear_size()];
		for(int i=0; i<SysType.m_Tile.get_linear_size(); i++)
		{
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_1::Write(pLoadingContext, SysType.m_Tile.linear_get_clamp(i), pData[i]);
		}
		TuaType.m_Tile.m_Data = pLoadingContext->ArchiveFile()->AddData((tua_uint8*) pData, sizeof(CAsset_MapLayerTiles::CTile::CTuaType_0_2_1)*SysType.m_Tile.get_linear_size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
	TuaType.m_PositionX = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_PositionX);
	TuaType.m_PositionY = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_PositionY);
}

void CAsset_MapLayerTiles::CTile::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapLayerTiles::CTile& SysType)
{
	SysType.m_Index = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Index);
	SysType.m_Flags = pLoadingContext->ArchiveFile()->ReadUInt8(TuaType.m_Flags);
}


void CAsset_MapLayerTiles::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapLayerTiles& SysType)
{
	CAsset::CTuaType_0_2_2::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	{
		const CAsset_MapLayerTiles::CTile::CTuaType_0_2_2* pData = (const CAsset_MapLayerTiles::CTile::CTuaType_0_2_2*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Tile.m_Data);
		uint32 Width = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Width);
		uint32 Height = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Height);
		uint32 Depth = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Tile.m_Depth);
		SysType.m_Tile.resize(Width, Height, Depth);
		int Size = Width * Height * Depth;
		for(int i=0; i<Size; i++)
		{
			CTile ReadedValue;
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_2::Read(pLoadingContext, pData[i], ReadedValue);
			SysType.m_Tile.linear_set_clamp(i, ReadedValue);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
	SysType.m_PositionX = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_PositionX);
	SysType.m_PositionY = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_PositionY);
}


void CAsset_MapLayerTiles::CTile::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles::CTile& SysType, CTuaType_0_2_2& TuaType)
{
	TuaType.m_Index = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Index);
	TuaType.m_Flags = pLoadingContext->ArchiveFile()->WriteUInt8(SysType.m_Flags);
}

void CAsset_MapLayerTiles::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles& SysType, CTuaType_0_2_2& TuaType)
{
	CAsset::CTuaType_0_2_2::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	{
		TuaType.m_Tile.m_Width = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_width());
		TuaType.m_Tile.m_Height = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_height());
		TuaType.m_Tile.m_Depth = pLoadingContext->ArchiveFile()->WriteUInt32(SysType.m_Tile.get_depth());
		CAsset_MapLayerTiles::CTile::CTuaType_0_2_2* pData = new CAsset_MapLayerTiles::CTile::CTuaType_0_2_2[SysType.m_Tile.get_linear_size()];
		for(int i=0; i<SysType.m_Tile.get_linear_size(); i++)
		{
			CAsset_MapLayerTiles::CTile::CTuaType_0_2_2::Write(pLoadingContext, SysType.m_Tile.linear_get_clamp(i), pData[i]);
		}
		TuaType.m_Tile.m_Data = pLoadingContext->ArchiveFile()->AddData((tua_uint8*) pData, sizeof(CAsset_MapLayerTiles::CTile::CTuaType_0_2_2)*SysType.m_Tile.get_linear_size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
	TuaType.m_PositionX = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_PositionX);
	TuaType.m_PositionY = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_PositionY);
}

template<>
int CAsset_MapLayerTiles::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case TILE_WIDTH:
			return GetTileWidth();
		case TILE_HEIGHT:
			return GetTileHeight();
		case TILE_INDEX:
			return GetTileIndex(SubPath);
		case TILE_FLAGS:
			return GetTileFlags(SubPath);
		case POSITIONX:
			return GetPositionX();
		case POSITIONY:
			return GetPositionY();
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapLayerTiles::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case TILE_WIDTH:
			SetTileWidth(Value);
			return true;
		case TILE_HEIGHT:
			SetTileHeight(Value);
			return true;
		case TILE_INDEX:
			SetTileIndex(SubPath, Value);
			return true;
		case TILE_FLAGS:
			SetTileFlags(SubPath, Value);
			return true;
		case POSITIONX:
			SetPositionX(Value);
			return true;
		case POSITIONY:
			SetPositionY(Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
bool CAsset_MapLayerTiles::GetValue(int ValueType, const CSubPath& SubPath, bool DefaultValue) const
{
	switch(ValueType)
	{
		case VISIBILITY:
			return GetVisibility();
	}
	return CAsset::GetValue<bool>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapLayerTiles::SetValue(int ValueType, const CSubPath& SubPath, bool Value)
{
	switch(ValueType)
	{
		case VISIBILITY:
			SetVisibility(Value);
			return true;
	}
	return CAsset::SetValue<bool>(ValueType, SubPath, Value);
}

template<>
vec4 CAsset_MapLayerTiles::GetValue(int ValueType, const CSubPath& SubPath, vec4 DefaultValue) const
{
	switch(ValueType)
	{
		case COLOR:
			return GetColor();
	}
	return CAsset::GetValue<vec4>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapLayerTiles::SetValue(int ValueType, const CSubPath& SubPath, vec4 Value)
{
	switch(ValueType)
	{
		case COLOR:
			SetColor(Value);
			return true;
	}
	return CAsset::SetValue<vec4>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_MapLayerTiles::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case PARENTPATH:
			return GetParentPath();
		case IMAGEPATH:
			return GetImagePath();
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapLayerTiles::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case PARENTPATH:
			SetParentPath(Value);
			return true;
		case IMAGEPATH:
			SetImagePath(Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_MapLayerTiles::AddSubItem(int Type, const CSubPath& SubPath)
{
	return -1;
}

int CAsset_MapLayerTiles::AddSubItemAt(int Type, const CSubPath& SubPath, int Index)
{
	return -1;
}

void CAsset_MapLayerTiles::DeleteSubItem(const CSubPath& SubPath)
{
}

void CAsset_MapLayerTiles::RelMoveSubItem(const CSubPath& SubPath, int RelMove)
{
}


