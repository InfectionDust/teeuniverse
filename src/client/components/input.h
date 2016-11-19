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

/*
 * Some parts of this file comes from other projects.
 * These parts are itendified in this file by the following block:
 * 
 * FOREIGN CODE BEGIN: ProjectName *************************************
 * 
 * FOREIGN CODE END: ProjectName ***************************************
 * 
 * If ProjectName is "TeeWorlds", then this part of the code follows the
 * TeeWorlds licence:
 *      (c) Magnus Auvinen. See LICENSE_TEEWORLDS in the root of the
 *      distribution for more information. If you are missing that file,
 *      acquire a complete release at teeworlds.com.
 */

#ifndef __CLIENT_INPUT__
#define __CLIENT_INPUT__

#include <client/kernel.h>
#include <shared/system/time.h>
#include <shared/tl/array.h>

#include <SDL.h>

/* FOREIGN CODE BEGIN: TeeWorlds **************************************/

const int g_MaxKeys = 512;
extern const char g_aaKeyStrings[g_MaxKeys][20];

class CInput : public CClientKernel::CComponent
{
public:
	class CEvent
	{
	public:
		int m_Flags;
		int m_Key;
		char m_aText[32];
		int m_InputCount;
	};

protected:
	enum
	{
		INPUT_BUFFER_SIZE=32
	};

	// quick access to events
	int m_NumEvents;
	CInput::CEvent m_aInputEvents[INPUT_BUFFER_SIZE];

public:
	enum
	{
		FLAG_PRESS=1,
		FLAG_RELEASE=2,
		FLAG_REPEAT=4,
		FLAG_TEXT=8,
	};
	
	struct CInputRect
	{
		int x;
		int y;
		int w;
		int h;
	};

public:
	int m_Cfg_Mousesens;

private:
	int m_InputGrabbed;
	bool m_TextEdited;
	bool m_Composing;
	dynamic_string m_EditedText;
	array<SDL_Rect> m_TextEditingQueue;

	int64 m_LastRelease;
	int64 m_ReleaseDelta;

	void AddEvent(char *pText, int Key, int Flags);

public:
	void Clear();
	int NumEvents() const { return m_NumEvents; } //From old interface
	bool IsEventValid(CEvent *pEvent) const { return pEvent->m_InputCount == m_InputCounter; };
	CEvent GetEvent(int Index) const //From old interface
	{
		if(Index < 0 || Index >= m_NumEvents)
		{
			CInput::CEvent e = {0,0};
			return e;
		}
		return m_aInputEvents[Index];
	}
	
	//quick access to input
	unsigned short m_aInputCount[g_MaxKeys];	// tw-KEY
	unsigned char m_aInputState[g_MaxKeys];	// SDL_SCANCODE
	int m_InputCounter;

	void ClearKeyStates();
	bool KeyState(int Key) const;

public:
	CInput(CClientKernel* pKernel);

	virtual bool InitConfig(int argc, const char** argv);
	virtual void SaveConfig(class CCLI_Output* pOutput);
	virtual bool Init();
	virtual bool PreUpdate();

	bool KeyIsPressed(int Key) const { return KeyState(Key); }
	bool KeyPress(int Key, bool CheckCounter) const { return CheckCounter ? (m_aInputCount[Key] == m_InputCounter) : m_aInputCount[Key]; }

	virtual void MouseRelative(float *x, float *y);
	virtual void MouseModeAbsolute();
	virtual void MouseModeRelative();
	virtual int MouseDoubleClick();

	virtual const char* GetEditedText() const;
	virtual void StartTextEditing(int x, int y, int w, int h);
	virtual void StopTextEditing();
	
	const char *KeyName(int Key) const { return (Key >= 0 && Key < g_MaxKeys) ? g_aaKeyStrings[Key] : g_aaKeyStrings[0]; } //From old interface
	virtual int KeyID(const char* pKeyName) const;
};

/* FOREIGN CODE END: TeeWorlds ****************************************/

#endif