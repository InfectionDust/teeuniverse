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

#ifndef TU_CLIENT_ASSETSINSPECTOR_H
#define TU_CLIENT_ASSETSINSPECTOR_H

#include <client/gui/tabs.h>
#include <client/gui/listlayout.h>

class CAssetsInspector : public gui::CTabs
{
	//Search Tag: TAG_NEW_ASSET
	enum
	{
		TAB_PACKAGE,
		TAB_GENERIC_ASSET,
		TAB_GUIRECTSTYLE_ASSET,
		TAB_GUILINESTYLE_ASSET,
		TAB_GUIBOXSTYLE_ASSET,
		TAB_GUILABELSTYLE_ASSET,
		TAB_GUIBUTTONSTYLE_ASSET,
		TAB_GUIINTEDITSTYLE_ASSET,
		TAB_GUITOGGLESTYLE_ASSET,
		TAB_GUISLIDERSTYLE_ASSET,
		TAB_GUISCROLLBARSTYLE_ASSET,
		TAB_GUITABSSTYLE_ASSET,
		TAB_IMAGE_ASSET,
		TAB_MAP_ASSET,
		TAB_MAPGROUP_ASSET,
		TAB_MAPLAYERTILES_ASSET,
		TAB_MAPLAYERQUADS_ASSET,
		TAB_MAPZONETILES_ASSET,
		TAB_SPRITE_ASSET,
		NUM_TABS
	};

private:
	class CGuiEditor* m_pAssetsEditor;
	gui::CVScrollLayout* m_pTabs[NUM_TABS];
	
private:
	void AddField(gui::CVListLayout* pList, gui::CWidget* pWidget, const char* pLabelText);
	void AddField_Text(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Integer(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Integer_NoEdit(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Color(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Float(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Vec2(gui::CVListLayout* pList, int Member, int Member2, const char* pLabelText);
	void AddField_Angle(gui::CVListLayout* pList, int Member, const char* pLabelText);
	void AddField_Asset(gui::CVListLayout* pList, int Member, int AssetType, const char* pLabelText);
	void AddField_AssetProperties(gui::CVScrollLayout* pList);

	//Search Tag: TAG_NEW_ASSET
	gui::CVScrollLayout* CreateTab_Package();
	gui::CVScrollLayout* CreateTab_Generic_Asset();
	gui::CVScrollLayout* CreateTab_GuiRectStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiLineStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiBoxStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiLabelStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiButtonStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiIntEditStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiToggleStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiSliderStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiScrollbarStyle_Asset();
	gui::CVScrollLayout* CreateTab_GuiTabsStyle_Asset();
	gui::CVScrollLayout* CreateTab_Image_Asset();
	gui::CVScrollLayout* CreateTab_Map_Asset();
	gui::CVScrollLayout* CreateTab_MapGroup_Asset();
	gui::CVScrollLayout* CreateTab_MapLayerTiles_Asset();
	gui::CVScrollLayout* CreateTab_MapLayerQuads_Asset();
	gui::CVScrollLayout* CreateTab_MapZoneTiles_Asset();
	gui::CVScrollLayout* CreateTab_Sprite_Asset();

public:
	CAssetsInspector(CGuiEditor* pAssetsEditor);
	
	virtual void Update(bool ParentEnabled);
	
	class CGuiEditor* AssetsEditor() { return m_pAssetsEditor; }
};

#endif