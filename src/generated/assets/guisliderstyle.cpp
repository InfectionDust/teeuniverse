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

#include <generated/assets/guisliderstyle.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_GuiSliderStyle::CAsset_GuiSliderStyle()
{
	m_Margin = 0;
	m_Padding = 0;
}

void CAsset_GuiSliderStyle::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_GuiSliderStyle& SysType)
{
	CAsset::CTuaType_0_1_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_RectPath, SysType.m_RectPath);
	pLoadingContext->ReadAssetPath(TuaType.m_DefaultRailPath, SysType.m_DefaultRailPath);
	pLoadingContext->ReadAssetPath(TuaType.m_CursorPath, SysType.m_CursorPath);
	SysType.m_Margin = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Margin);
	SysType.m_Padding = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Padding);
}


void CAsset_GuiSliderStyle::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiSliderStyle& SysType, CTuaType_0_1_0& TuaType)
{
	CAsset::CTuaType_0_1_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_RectPath, TuaType.m_RectPath);
	pLoadingContext->WriteAssetPath(SysType.m_DefaultRailPath, TuaType.m_DefaultRailPath);
	pLoadingContext->WriteAssetPath(SysType.m_CursorPath, TuaType.m_CursorPath);
	TuaType.m_Margin = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Margin);
	TuaType.m_Padding = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Padding);
}

void CAsset_GuiSliderStyle::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_GuiSliderStyle& SysType)
{
	CAsset::CTuaType_0_2_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_RectPath, SysType.m_RectPath);
	pLoadingContext->ReadAssetPath(TuaType.m_DefaultRailPath, SysType.m_DefaultRailPath);
	pLoadingContext->ReadAssetPath(TuaType.m_CursorPath, SysType.m_CursorPath);
	SysType.m_Margin = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Margin);
	SysType.m_Padding = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Padding);
}


void CAsset_GuiSliderStyle::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiSliderStyle& SysType, CTuaType_0_2_0& TuaType)
{
	CAsset::CTuaType_0_2_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_RectPath, TuaType.m_RectPath);
	pLoadingContext->WriteAssetPath(SysType.m_DefaultRailPath, TuaType.m_DefaultRailPath);
	pLoadingContext->WriteAssetPath(SysType.m_CursorPath, TuaType.m_CursorPath);
	TuaType.m_Margin = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Margin);
	TuaType.m_Padding = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Padding);
}

template<>
int CAsset_GuiSliderStyle::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case MARGIN:
			return GetMargin();
		case PADDING:
			return GetPadding();
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_GuiSliderStyle::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case MARGIN:
			SetMargin(Value);
			return true;
		case PADDING:
			SetPadding(Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_GuiSliderStyle::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case RECTPATH:
			return GetRectPath();
		case DEFAULTRAILPATH:
			return GetDefaultRailPath();
		case CURSORPATH:
			return GetCursorPath();
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_GuiSliderStyle::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case RECTPATH:
			SetRectPath(Value);
			return true;
		case DEFAULTRAILPATH:
			SetDefaultRailPath(Value);
			return true;
		case CURSORPATH:
			SetCursorPath(Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_GuiSliderStyle::AddSubItem(int Type, const CSubPath& SubPath)
{
	return -1;
}

int CAsset_GuiSliderStyle::AddSubItemAt(int Type, const CSubPath& SubPath, int Index)
{
	return -1;
}

void CAsset_GuiSliderStyle::DeleteSubItem(const CSubPath& SubPath)
{
}

void CAsset_GuiSliderStyle::RelMoveSubItem(const CSubPath& SubPath, int RelMove)
{
}


