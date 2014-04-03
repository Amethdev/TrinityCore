// Hello Guys. Im amethdev And i wanna Show You my Custom Worldboss Made for YOU!
Its easy Just change the name where is "Nameoftheboss" And the Spell ids
Have fun!
//
/*
 * Copyright (C) 20010-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 20010-2015 Amethdev /////////////////////////////////
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: Worldboss.cpp
%Complete: 100
Comment: Custom boss Template.
Author: Amethdev
Category: Custom Script
EndScriptData */


struct Nameoftheboss : public ScriptedAI
{
	NameofthebossAI(Creature *c) : ScriptedAI(c)
	{
	}

	uint32 spell1_Timer;
	uint32 phase1_Percent;
	uint32 phase;

	bool enraged;

	void EnterCombat(Unit *who)
	{
		m_creature->MonsterYell("Yellonentercombat", LANG_UNIVERSAL, NULL);
		DoCast(m_creature, Spellidhere);
	}

	void KilledUnit(Unit* victim)
	{
		m_creature->MonsterYell("YellonKilledplayer", LANG_UNIVERSAL, NULL);
		DoCast(m_creature, Spellidhere);
	}
	
  	void Reset()
	{
		spell1_Timer = 0+rand()%8000;
		phase1_Percent = 99;
		phase = 0;
		enraged = false;
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		if ((m_creature->GetHealth() * 100 / m_creature->GetMaxHealth() <= 99) && !enraged)
		{
			enraged = true;
			DoCast(m_creature, Spellidhere);
			m_creature->MonsterYell("YellOnenrage(start)", LANG_UNIVERSAL, NULL);
		}

		if ((m_creature->GetHealth() * 100 / m_creature->GetMaxHealth() <= 99) 
		{
			phase = 1;
			m_creature->MonsterYell("OnHealYell", LANG_UNIVERSAL, NULL);
		}


		if (spell1_Timer <= diff)
		{
			DoCast(m_creature, 48951);
			spell1_Timer = 0+rand()%8000;
		} else spell1_Timer -= diff;

		DoMeleeAttackIfReady();
	}
};


CreatureAI* GetAINameoftheboss(Creature* pCreature)
{
	return new NameofthebossAI (pCreature);
}


void AddSC_Nameoftheboss()
{
  new Nameoftheboss;
}
