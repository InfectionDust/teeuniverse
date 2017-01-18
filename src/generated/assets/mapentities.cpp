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

#include <generated/assets/mapentities.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_MapEntities::CEntity::CEntity()
{
	m_Position = 0.0f;
}

CAsset_MapEntities::CAsset_MapEntities()
{
	m_Visibility = true;
}

void CAsset_MapEntities::CEntity::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapEntities::CEntity& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_TypePath, SysType.m_TypePath);
	SysType.m_Position.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_X);
	SysType.m_Position.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_Y);
}


void CAsset_MapEntities::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapEntities& SysType)
{
	CAsset::CTuaType_0_1_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	{
		const CAsset_MapEntities::CEntity::CTuaType_0_1_0* pData = (const CAsset_MapEntities::CEntity::CTuaType_0_1_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Entity.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Entity.m_Size);
		SysType.m_Entity.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_1_0::Read(pLoadingContext, pData[i], SysType.m_Entity[i]);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapEntities::CEntity::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_1_0& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_TypePath, TuaType.m_TypePath);
	TuaType.m_Position.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.x);
	TuaType.m_Position.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.y);
}

void CAsset_MapEntities::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_1_0& TuaType)
{
	CAsset::CTuaType_0_1_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	{
		TuaType.m_Entity.m_Size = SysType.m_Entity.size();
		CAsset_MapEntities::CEntity::CTuaType_0_1_0* pData = new CAsset_MapEntities::CEntity::CTuaType_0_1_0[SysType.m_Entity.size()];
		for(int i=0; i<SysType.m_Entity.size(); i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_1_0::Write(pLoadingContext, SysType.m_Entity[i], pData[i]);
		}
		TuaType.m_Entity.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_MapEntities::CEntity::CTuaType_0_1_0)*SysType.m_Entity.size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

void CAsset_MapEntities::CEntity::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapEntities::CEntity& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_TypePath, SysType.m_TypePath);
	SysType.m_Position.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_X);
	SysType.m_Position.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_Y);
}


void CAsset_MapEntities::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapEntities& SysType)
{
	CAsset::CTuaType_0_2_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	{
		const CAsset_MapEntities::CEntity::CTuaType_0_2_0* pData = (const CAsset_MapEntities::CEntity::CTuaType_0_2_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Entity.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Entity.m_Size);
		SysType.m_Entity.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_0::Read(pLoadingContext, pData[i], SysType.m_Entity[i]);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapEntities::CEntity::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_0& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_TypePath, TuaType.m_TypePath);
	TuaType.m_Position.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.x);
	TuaType.m_Position.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.y);
}

void CAsset_MapEntities::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_0& TuaType)
{
	CAsset::CTuaType_0_2_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	{
		TuaType.m_Entity.m_Size = SysType.m_Entity.size();
		CAsset_MapEntities::CEntity::CTuaType_0_2_0* pData = new CAsset_MapEntities::CEntity::CTuaType_0_2_0[SysType.m_Entity.size()];
		for(int i=0; i<SysType.m_Entity.size(); i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_0::Write(pLoadingContext, SysType.m_Entity[i], pData[i]);
		}
		TuaType.m_Entity.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_MapEntities::CEntity::CTuaType_0_2_0)*SysType.m_Entity.size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

void CAsset_MapEntities::CEntity::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapEntities::CEntity& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_TypePath, SysType.m_TypePath);
	SysType.m_Position.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_X);
	SysType.m_Position.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_Y);
}


void CAsset_MapEntities::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapEntities& SysType)
{
	CAsset::CTuaType_0_2_1::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	{
		const CAsset_MapEntities::CEntity::CTuaType_0_2_1* pData = (const CAsset_MapEntities::CEntity::CTuaType_0_2_1*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Entity.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Entity.m_Size);
		SysType.m_Entity.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_1::Read(pLoadingContext, pData[i], SysType.m_Entity[i]);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapEntities::CEntity::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_1& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_TypePath, TuaType.m_TypePath);
	TuaType.m_Position.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.x);
	TuaType.m_Position.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.y);
}

void CAsset_MapEntities::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_1& TuaType)
{
	CAsset::CTuaType_0_2_1::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	{
		TuaType.m_Entity.m_Size = SysType.m_Entity.size();
		CAsset_MapEntities::CEntity::CTuaType_0_2_1* pData = new CAsset_MapEntities::CEntity::CTuaType_0_2_1[SysType.m_Entity.size()];
		for(int i=0; i<SysType.m_Entity.size(); i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_1::Write(pLoadingContext, SysType.m_Entity[i], pData[i]);
		}
		TuaType.m_Entity.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_MapEntities::CEntity::CTuaType_0_2_1)*SysType.m_Entity.size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

void CAsset_MapEntities::CEntity::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapEntities::CEntity& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_TypePath, SysType.m_TypePath);
	SysType.m_Position.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_X);
	SysType.m_Position.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_Y);
}


void CAsset_MapEntities::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapEntities& SysType)
{
	CAsset::CTuaType_0_2_2::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_ParentPath, SysType.m_ParentPath);
	{
		const CAsset_MapEntities::CEntity::CTuaType_0_2_2* pData = (const CAsset_MapEntities::CEntity::CTuaType_0_2_2*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Entity.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Entity.m_Size);
		SysType.m_Entity.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_2::Read(pLoadingContext, pData[i], SysType.m_Entity[i]);
		}
	}
	
	SysType.m_Visibility = pLoadingContext->ArchiveFile()->ReadBool(TuaType.m_Visibility);
}


void CAsset_MapEntities::CEntity::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_2& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_TypePath, TuaType.m_TypePath);
	TuaType.m_Position.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.x);
	TuaType.m_Position.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.y);
}

void CAsset_MapEntities::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_2& TuaType)
{
	CAsset::CTuaType_0_2_2::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_ParentPath, TuaType.m_ParentPath);
	{
		TuaType.m_Entity.m_Size = SysType.m_Entity.size();
		CAsset_MapEntities::CEntity::CTuaType_0_2_2* pData = new CAsset_MapEntities::CEntity::CTuaType_0_2_2[SysType.m_Entity.size()];
		for(int i=0; i<SysType.m_Entity.size(); i++)
		{
			CAsset_MapEntities::CEntity::CTuaType_0_2_2::Write(pLoadingContext, SysType.m_Entity[i], pData[i]);
		}
		TuaType.m_Entity.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_MapEntities::CEntity::CTuaType_0_2_2)*SysType.m_Entity.size());
		delete[] pData;
	}
	TuaType.m_Visibility = pLoadingContext->ArchiveFile()->WriteBool(SysType.m_Visibility);
}

template<>
int CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_ARRAYSIZE:
			return GetEntityArraySize();
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case ENTITY_ARRAYSIZE:
			SetEntityArraySize(Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
bool CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, bool DefaultValue) const
{
	switch(ValueType)
	{
		case VISIBILITY:
			return GetVisibility();
	}
	return CAsset::GetValue<bool>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, bool Value)
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
float CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, float DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_POSITION_X:
			return GetEntityPositionX(SubPath);
		case ENTITY_POSITION_Y:
			return GetEntityPositionY(SubPath);
	}
	return CAsset::GetValue<float>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, float Value)
{
	switch(ValueType)
	{
		case ENTITY_POSITION_X:
			SetEntityPositionX(SubPath, Value);
			return true;
		case ENTITY_POSITION_Y:
			SetEntityPositionY(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<float>(ValueType, SubPath, Value);
}

template<>
vec2 CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, vec2 DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_POSITION:
			return GetEntityPosition(SubPath);
	}
	return CAsset::GetValue<vec2>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, vec2 Value)
{
	switch(ValueType)
	{
		case ENTITY_POSITION:
			SetEntityPosition(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<vec2>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case PARENTPATH:
			return GetParentPath();
		case ENTITY_TYPEPATH:
			return GetEntityTypePath(SubPath);
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case PARENTPATH:
			SetParentPath(Value);
			return true;
		case ENTITY_TYPEPATH:
			SetEntityTypePath(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_MapEntities::AddSubItem(int Type, const CSubPath& SubPath)
{
	switch(Type)
	{
		case TYPE_ENTITY:
			return AddEntity();
	}
	return -1;
}

int CAsset_MapEntities::AddSubItemAt(int Type, const CSubPath& SubPath, int Index)
{
	switch(Type)
	{
		case TYPE_ENTITY:
			AddAtEntity(Index);
			return Index;
	}
	return -1;
}

void CAsset_MapEntities::DeleteSubItem(const CSubPath& SubPath)
{
	switch(SubPath.GetType())
	{
		case TYPE_ENTITY:
			DeleteEntity(SubPath);
			break;
	}
}

void CAsset_MapEntities::RelMoveSubItem(const CSubPath& SubPath, int RelMove)
{
	switch(SubPath.GetType())
	{
		case TYPE_ENTITY:
			RelMoveEntity(SubPath, RelMove);
			break;
	}
}


