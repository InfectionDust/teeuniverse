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

#ifndef __CLIENT_ASSETS_GUITABSSTYLE__
#define __CLIENT_ASSETS_GUITABSSTYLE__

#include <shared/assets/asset.h>
#include <shared/assets/assetpath.h>

class CAsset_GuiTabsStyle : public CAsset
{
public:
	static const int TypeId = 11;
	
	enum
	{
		NAME = CAsset::NAME,
		LAYOUTPATH,
		CONTENTPATH,
		BUTTONLISTPATH,
		INACTIVEBUTTONPATH,
		ACTIVEBUTTONPATH,
		BUTTONLISTFILL,
		BUTTONLISTTEXT,
	};
	
	class CTuaType_0_1_0 : public CAsset::CTuaType_0_1_0
	{
	public:
		CAssetPath::CTuaType m_LayoutPath;
		CAssetPath::CTuaType m_ContentPath;
		CAssetPath::CTuaType m_ButtonListPath;
		CAssetPath::CTuaType m_InactiveButtonPath;
		CAssetPath::CTuaType m_ActiveButtonPath;
		tua_uint8 m_ButtonListFill;
		tua_uint8 m_ButtonListText;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_GuiTabsStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiTabsStyle& SysType, CTuaType_0_1_0& TuaType);
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		CAssetPath::CTuaType m_LayoutPath;
		CAssetPath::CTuaType m_ContentPath;
		CAssetPath::CTuaType m_ButtonListPath;
		CAssetPath::CTuaType m_InactiveButtonPath;
		CAssetPath::CTuaType m_ActiveButtonPath;
		tua_uint8 m_ButtonListFill;
		tua_uint8 m_ButtonListText;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_GuiTabsStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiTabsStyle& SysType, CTuaType_0_2_0& TuaType);
	};
	

private:
	CAssetPath m_LayoutPath;
	CAssetPath m_ContentPath;
	CAssetPath m_ButtonListPath;
	CAssetPath m_InactiveButtonPath;
	CAssetPath m_ActiveButtonPath;
	bool m_ButtonListFill;
	bool m_ButtonListText;

public:
	template<typename T>
	T GetValue(int ValueType, const CSubPath& SubPath, T DefaultValue) const
	{
		return CAsset::GetValue<T>(ValueType, SubPath, DefaultValue);
	}
	
	template<typename T>
	bool SetValue(int ValueType, const CSubPath& SubPath, T Value)
	{
		return CAsset::SetValue<T>(ValueType, SubPath, Value);
	}
	
	int AddSubItem(int Type, const CSubPath& SubPath);
	
	int AddSubItemAt(int Type, const CSubPath& SubPath, int Index);
	
	void DeleteSubItem(const CSubPath& SubPath);
	
	void RelMoveSubItem(const CSubPath& SubPath, int RelMove);
	
	CAsset_GuiTabsStyle();
	void copy(const CAsset_GuiTabsStyle& Item)
	{
		CAsset::copy(Item);
		m_LayoutPath = Item.m_LayoutPath;
		m_ContentPath = Item.m_ContentPath;
		m_ButtonListPath = Item.m_ButtonListPath;
		m_InactiveButtonPath = Item.m_InactiveButtonPath;
		m_ActiveButtonPath = Item.m_ActiveButtonPath;
		m_ButtonListFill = Item.m_ButtonListFill;
		m_ButtonListText = Item.m_ButtonListText;
	}
	
	void transfert(CAsset_GuiTabsStyle& Item)
	{
		CAsset::transfert(Item);
		m_LayoutPath = Item.m_LayoutPath;
		m_ContentPath = Item.m_ContentPath;
		m_ButtonListPath = Item.m_ButtonListPath;
		m_InactiveButtonPath = Item.m_InactiveButtonPath;
		m_ActiveButtonPath = Item.m_ActiveButtonPath;
		m_ButtonListFill = Item.m_ButtonListFill;
		m_ButtonListText = Item.m_ButtonListText;
	}
	
	inline CAssetPath GetLayoutPath() const { return m_LayoutPath; }
	
	inline CAssetPath GetContentPath() const { return m_ContentPath; }
	
	inline CAssetPath GetButtonListPath() const { return m_ButtonListPath; }
	
	inline CAssetPath GetInactiveButtonPath() const { return m_InactiveButtonPath; }
	
	inline CAssetPath GetActiveButtonPath() const { return m_ActiveButtonPath; }
	
	inline bool GetButtonListFill() const { return m_ButtonListFill; }
	
	inline bool GetButtonListText() const { return m_ButtonListText; }
	
	inline void SetLayoutPath(const CAssetPath& Value) { m_LayoutPath = Value; }
	
	inline void SetContentPath(const CAssetPath& Value) { m_ContentPath = Value; }
	
	inline void SetButtonListPath(const CAssetPath& Value) { m_ButtonListPath = Value; }
	
	inline void SetInactiveButtonPath(const CAssetPath& Value) { m_InactiveButtonPath = Value; }
	
	inline void SetActiveButtonPath(const CAssetPath& Value) { m_ActiveButtonPath = Value; }
	
	inline void SetButtonListFill(bool Value) { m_ButtonListFill = Value; }
	
	inline void SetButtonListText(bool Value) { m_ButtonListText = Value; }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_LayoutPath);
		Operation.Apply(m_ContentPath);
		Operation.Apply(m_ButtonListPath);
		Operation.Apply(m_InactiveButtonPath);
		Operation.Apply(m_ActiveButtonPath);
	}
	
};

template<> bool CAsset_GuiTabsStyle::GetValue(int ValueType, const CSubPath& SubPath, bool DefaultValue) const;
template<> bool CAsset_GuiTabsStyle::SetValue(int ValueType, const CSubPath& SubPath, bool Value);
template<> CAssetPath CAsset_GuiTabsStyle::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_GuiTabsStyle::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);

#endif
