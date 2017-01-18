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

#ifndef __CLIENT_ASSETS_GUILABELSTYLE__
#define __CLIENT_ASSETS_GUILABELSTYLE__

#include <shared/assets/asset.h>
#include <shared/math/vector.h>
#include <shared/assets/assetpath.h>

class CAsset_GuiLabelStyle : public CAsset
{
public:
	enum
	{
		TEXTALIGNMENT_LEFT=0,
		TEXTALIGNMENT_CENTER,
		TEXTALIGNMENT_RIGHT,
		TEXTALIGNMENT_BELOW_CENTER,
		TEXTALIGNMENT_BELOW_CENTER_EXTENDED,
	};
	
	static const int TypeId = 5;
	
	enum
	{
		NAME = CAsset::NAME,
		MINWIDTH,
		MINHEIGHT,
		MARGIN,
		PADDING,
		SPACING,
		FONTSIZE,
		TEXTCOLOR,
		TEXTALIGNMENT,
		RECTPATH,
		ICONPATH,
	};
	
	class CTuaType_0_1_0 : public CAsset::CTuaType_0_1_0
	{
	public:
		tua_int32 m_MinWidth;
		tua_int32 m_MinHeight;
		tua_int32 m_Margin;
		tua_int32 m_Padding;
		tua_int32 m_Spacing;
		tua_int32 m_FontSize;
		tua_uint32 m_TextColor;
		tua_int32 m_TextAlignment;
		CAssetPath::CTuaType m_RectPath;
		CAssetPath::CTuaType m_IconPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_GuiLabelStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLabelStyle& SysType, CTuaType_0_1_0& TuaType);
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		tua_int32 m_MinWidth;
		tua_int32 m_MinHeight;
		tua_int32 m_Margin;
		tua_int32 m_Padding;
		tua_int32 m_Spacing;
		tua_int32 m_FontSize;
		tua_uint32 m_TextColor;
		tua_int32 m_TextAlignment;
		CAssetPath::CTuaType m_RectPath;
		CAssetPath::CTuaType m_IconPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_GuiLabelStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLabelStyle& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		tua_int32 m_MinWidth;
		tua_int32 m_MinHeight;
		tua_int32 m_Margin;
		tua_int32 m_Padding;
		tua_int32 m_Spacing;
		tua_int32 m_FontSize;
		tua_uint32 m_TextColor;
		tua_int32 m_TextAlignment;
		CAssetPath::CTuaType m_RectPath;
		CAssetPath::CTuaType m_IconPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_GuiLabelStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLabelStyle& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		tua_int32 m_MinWidth;
		tua_int32 m_MinHeight;
		tua_int32 m_Margin;
		tua_int32 m_Padding;
		tua_int32 m_Spacing;
		tua_int32 m_FontSize;
		tua_uint32 m_TextColor;
		tua_int32 m_TextAlignment;
		CAssetPath::CTuaType m_RectPath;
		CAssetPath::CTuaType m_IconPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_GuiLabelStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLabelStyle& SysType, CTuaType_0_2_2& TuaType);
	};
	

private:
	int m_MinWidth;
	int m_MinHeight;
	int m_Margin;
	int m_Padding;
	int m_Spacing;
	int m_FontSize;
	vec4 m_TextColor;
	int m_TextAlignment;
	CAssetPath m_RectPath;
	CAssetPath m_IconPath;

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
	
	CAsset_GuiLabelStyle();
	void copy(const CAsset_GuiLabelStyle& Item)
	{
		CAsset::copy(Item);
		m_MinWidth = Item.m_MinWidth;
		m_MinHeight = Item.m_MinHeight;
		m_Margin = Item.m_Margin;
		m_Padding = Item.m_Padding;
		m_Spacing = Item.m_Spacing;
		m_FontSize = Item.m_FontSize;
		m_TextColor = Item.m_TextColor;
		m_TextAlignment = Item.m_TextAlignment;
		m_RectPath = Item.m_RectPath;
		m_IconPath = Item.m_IconPath;
	}
	
	void transfert(CAsset_GuiLabelStyle& Item)
	{
		CAsset::transfert(Item);
		m_MinWidth = Item.m_MinWidth;
		m_MinHeight = Item.m_MinHeight;
		m_Margin = Item.m_Margin;
		m_Padding = Item.m_Padding;
		m_Spacing = Item.m_Spacing;
		m_FontSize = Item.m_FontSize;
		m_TextColor = Item.m_TextColor;
		m_TextAlignment = Item.m_TextAlignment;
		m_RectPath = Item.m_RectPath;
		m_IconPath = Item.m_IconPath;
	}
	
	inline int GetMinWidth() const { return m_MinWidth; }
	
	inline int GetMinHeight() const { return m_MinHeight; }
	
	inline int GetMargin() const { return m_Margin; }
	
	inline int GetPadding() const { return m_Padding; }
	
	inline int GetSpacing() const { return m_Spacing; }
	
	inline int GetFontSize() const { return m_FontSize; }
	
	inline vec4 GetTextColor() const { return m_TextColor; }
	
	inline int GetTextAlignment() const { return m_TextAlignment; }
	
	inline CAssetPath GetRectPath() const { return m_RectPath; }
	
	inline CAssetPath GetIconPath() const { return m_IconPath; }
	
	inline void SetMinWidth(int Value) { m_MinWidth = Value; }
	
	inline void SetMinHeight(int Value) { m_MinHeight = Value; }
	
	inline void SetMargin(int Value) { m_Margin = Value; }
	
	inline void SetPadding(int Value) { m_Padding = Value; }
	
	inline void SetSpacing(int Value) { m_Spacing = Value; }
	
	inline void SetFontSize(int Value) { m_FontSize = Value; }
	
	inline void SetTextColor(vec4 Value) { m_TextColor = Value; }
	
	inline void SetTextAlignment(int Value) { m_TextAlignment = Value; }
	
	inline void SetRectPath(const CAssetPath& Value) { m_RectPath = Value; }
	
	inline void SetIconPath(const CAssetPath& Value) { m_IconPath = Value; }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_RectPath);
		Operation.Apply(m_IconPath);
	}
	
};

template<> int CAsset_GuiLabelStyle::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const;
template<> bool CAsset_GuiLabelStyle::SetValue(int ValueType, const CSubPath& SubPath, int Value);
template<> vec4 CAsset_GuiLabelStyle::GetValue(int ValueType, const CSubPath& SubPath, vec4 DefaultValue) const;
template<> bool CAsset_GuiLabelStyle::SetValue(int ValueType, const CSubPath& SubPath, vec4 Value);
template<> CAssetPath CAsset_GuiLabelStyle::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_GuiLabelStyle::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);

#endif
