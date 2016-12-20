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

#include <generated/assets/sprite.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_Sprite::CAsset_Sprite()
{
	m_X = 0;
	m_Y = 0;
	m_Width = 1;
	m_Height = 1;
}

void CAsset_Sprite::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_Sprite& SysType)
{
	CAsset::CTuaType_0_1_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_X = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_X);
	SysType.m_Y = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Y);
	SysType.m_Width = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Width);
	SysType.m_Height = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Height);
}


void CAsset_Sprite::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_Sprite& SysType, CTuaType_0_1_0& TuaType)
{
	CAsset::CTuaType_0_1_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_X = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_X);
	TuaType.m_Y = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Y);
	TuaType.m_Width = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Width);
	TuaType.m_Height = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Height);
}

void CAsset_Sprite::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_Sprite& SysType)
{
	CAsset::CTuaType_0_2_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ImagePath, SysType.m_ImagePath);
	SysType.m_X = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_X);
	SysType.m_Y = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Y);
	SysType.m_Width = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Width);
	SysType.m_Height = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Height);
}


void CAsset_Sprite::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_Sprite& SysType, CTuaType_0_2_0& TuaType)
{
	CAsset::CTuaType_0_2_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ImagePath, TuaType.m_ImagePath);
	TuaType.m_X = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_X);
	TuaType.m_Y = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Y);
	TuaType.m_Width = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Width);
	TuaType.m_Height = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Height);
}

template<>
int CAsset_Sprite::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case X:
			return GetX();
		case Y:
			return GetY();
		case WIDTH:
			return GetWidth();
		case HEIGHT:
			return GetHeight();
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_Sprite::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case X:
			SetX(Value);
			return true;
		case Y:
			SetY(Value);
			return true;
		case WIDTH:
			SetWidth(Value);
			return true;
		case HEIGHT:
			SetHeight(Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_Sprite::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case IMAGEPATH:
			return GetImagePath();
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_Sprite::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case IMAGEPATH:
			SetImagePath(Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_Sprite::AddSubItem(int Type, const CSubPath& SubPath)
{
	return -1;
}

int CAsset_Sprite::AddSubItemAt(int Type, const CSubPath& SubPath, int Index)
{
	return -1;
}

void CAsset_Sprite::DeleteSubItem(const CSubPath& SubPath)
{
}

void CAsset_Sprite::RelMoveSubItem(const CSubPath& SubPath, int RelMove)
{
}


