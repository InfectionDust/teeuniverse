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

#ifndef __CLIENT_ASSETS_CHARACTERPART__
#define __CLIENT_ASSETS_CHARACTERPART__

#include <shared/assets/asset.h>
#include <shared/assets/assetpath.h>

class CAsset_CharacterPart : public CAsset
{
public:
	static const int TypeId = 1;
	
	enum
	{
		NAME = CAsset::NAME,
		CHARACTERPATH,
		CHARACTERPART,
		SKELETONSKINPATH,
	};
	
	class CTuaType_0_1_0 : public CAsset::CTuaType_0_1_0
	{
	public:
		CAssetPath::CTuaType m_CharacterPath;
		CSubPath::CTuaType m_CharacterPart;
		CAssetPath::CTuaType m_SkeletonSkinPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_CharacterPart& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_CharacterPart& SysType, CTuaType_0_1_0& TuaType);
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		CAssetPath::CTuaType m_CharacterPath;
		CSubPath::CTuaType m_CharacterPart;
		CAssetPath::CTuaType m_SkeletonSkinPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_CharacterPart& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_CharacterPart& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		CAssetPath::CTuaType m_CharacterPath;
		CSubPath::CTuaType m_CharacterPart;
		CAssetPath::CTuaType m_SkeletonSkinPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_CharacterPart& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_CharacterPart& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		CAssetPath::CTuaType m_CharacterPath;
		CSubPath::CTuaType m_CharacterPart;
		CAssetPath::CTuaType m_SkeletonSkinPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_CharacterPart& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_CharacterPart& SysType, CTuaType_0_2_2& TuaType);
	};
	

private:
	CAssetPath m_CharacterPath;
	CSubPath m_CharacterPart;
	CAssetPath m_SkeletonSkinPath;

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
	
	void copy(const CAsset_CharacterPart& Item)
	{
		CAsset::copy(Item);
		m_CharacterPath = Item.m_CharacterPath;
		m_CharacterPart = Item.m_CharacterPart;
		m_SkeletonSkinPath = Item.m_SkeletonSkinPath;
	}
	
	void transfert(CAsset_CharacterPart& Item)
	{
		CAsset::transfert(Item);
		m_CharacterPath = Item.m_CharacterPath;
		m_CharacterPart = Item.m_CharacterPart;
		m_SkeletonSkinPath = Item.m_SkeletonSkinPath;
	}
	
	inline CAssetPath GetCharacterPath() const { return m_CharacterPath; }
	
	inline CSubPath GetCharacterPart() const { return m_CharacterPart; }
	
	inline CAssetPath GetSkeletonSkinPath() const { return m_SkeletonSkinPath; }
	
	inline void SetCharacterPath(const CAssetPath& Value) { m_CharacterPath = Value; }
	
	inline void SetCharacterPart(const CSubPath& Value) { m_CharacterPart = Value; }
	
	inline void SetSkeletonSkinPath(const CAssetPath& Value) { m_SkeletonSkinPath = Value; }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_CharacterPath);
		Operation.Apply(m_SkeletonSkinPath);
	}
	
};

template<> CAssetPath CAsset_CharacterPart::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_CharacterPart::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);
template<> CSubPath CAsset_CharacterPart::GetValue(int ValueType, const CSubPath& SubPath, CSubPath DefaultValue) const;
template<> bool CAsset_CharacterPart::SetValue(int ValueType, const CSubPath& SubPath, CSubPath Value);

#endif
