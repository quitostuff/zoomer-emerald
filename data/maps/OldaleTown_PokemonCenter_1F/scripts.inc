.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WaldaPhrase_Test::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferPassword
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_PokemonCenter_1F_EventScript_FirstWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_NewWaldaPhrase

OldaleTown_PokemonCenter_1F_EventScript_FirstWaldaPhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_FirstPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_DeclineGivePhrase
	msgbox OldaleTown_PokemonCenter_1F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_GivePhrase

OldaleTown_PokemonCenter_1F_EventScript_NewWaldaPhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_NewPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_DeclineGivePhrase
	msgbox OldaleTown_PokemonCenter_1F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_GivePhrase

OldaleTown_PokemonCenter_1F_EventScript_DeclineGivePhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_CancelGivePhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_GivePhrase::
	special DoPasswordScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, OldaleTown_PokemonCenter_1F_EventScript_CancelGivePhrase
	specialvar VAR_RESULT, TryGiveMonWithPassword
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_IsWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_PokemonCenter_1F_EventScript_NotWaldaPhrase
	end

OldaleTown_PokemonCenter_1F_EventScript_IsWaldaPhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_GoodWaldaPhrase, MSGBOX_DEFAULT
	givemon VAR_0x8006, 10
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_NotWaldaPhrase::
	msgbox OldaleTown_PokemonCenter_1F_Text_NotWaldaPhrase, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

OldaleTown_PokemonCenter_1F_Text_FirstPhrase:
	.string "Hello, I'm here to test if the\n"
	.string "Walda phrase script works.\p"
	.string "Do you have a funny thing to say to me?$"

OldaleTown_PokemonCenter_1F_Text_NewPhrase:
	.string "Would you like to tell me\n"
	.string "a new Walda Phrase?$"

OldaleTown_PokemonCenter_1F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, that's wonderful.\n"
	.string "So, let's hear it, your suggestion.$"

OldaleTown_PokemonCenter_1F_Text_OhIsThatRight:
	.string "Oh, is that right?\p"
	.string "Well, if you come up with a good\n"
	.string "suggestion, I'm all ears.$"

OldaleTown_PokemonCenter_1F_Text_OhYouDontKnowAny:
	.string "Oh, so you don't know any good words.\n"
	.string "I guess I'll try to amuse her with\l"
	.string "the saying I used before.\p"
	.string "Anyways, if you have a good suggestion,\n"
	.string "don't hesitate in telling me, okay?$"

OldaleTown_PokemonCenter_1F_Text_GoodWaldaPhrase:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, yes! It worked!\n"
	.string "You actually found a Walda Phrase!$"

OldaleTown_PokemonCenter_1F_Text_NotWaldaPhrase:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Well, this isn't a funny phrase.\p"
	.string "Maybe try again next time!\n"
	.string "It's hard to find a working Walda Phrase.$"
