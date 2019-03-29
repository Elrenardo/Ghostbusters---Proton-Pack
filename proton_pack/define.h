//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Definition Programme
BY      : Teysseire Guillaume
TIME    : 03/12/2018
UPDA    : 03/12/2018
WEB     : studiogoupil.fr
VERSION : 1.00
*/
//-------------------------------------------------------
//-------------------------------------------------------
//GLOBAL

#define PROTON_DEBUG //Activer ou pas le mode debug du proton pack
#define PROTON_DEBUG_SERIAL 115200 //Dialogue PC serial


//-------------------------------------------------------
//-------------------------------------------------------
//AUDIO

#define AUDIO_VOLUME 30 //Set volume value. From 0 to 30
#define AUDIO_RX 12 //port
#define AUDIO_TX 13 //port
#define AUDIO_PORT_INIT 9600 //Port init audio card

//Audio Position list .mp3 dans la carte SD
#define AUDIO_GHOSTBUSTERS    1

#define AUDIO_PLAY_PACK_ON    3
#define AUDIO_PLAY_PACK_OFF   5

#define AUDIO_PLAY_GUN_ON     6
#define AUDIO_PLAY_GUN_VENT   9
#define AUDIO_PLAY_FUMEE      4

#define AUDIO_PLAY_STREAM_ON  7
#define AUDIO_PLAY_STREAM     8
#define AUDIO_PLAY_STREAM_OFF 2


//-------------------------------------------------------
//-------------------------------------------------------
//POWER CELL

#define POWERCELL_01 6 //ok
#define POWERCELL_02 7 //ok
#define POWERCELL_03 4 //ok
#define POWERCELL_04 5 //ok
#define POWERCELL_05 28 //ok
#define POWERCELL_06 30 //ok
#define POWERCELL_07 32 //ok
#define POWERCELL_08 34 //ok
#define POWERCELL_09 24 //ok
#define POWERCELL_10 26 //ok
#define POWERCELL_11 36 //ok
#define POWERCELL_12 38 //ok


//-------------------------------------------------------
//-------------------------------------------------------
//CYCLOTRON

#define CYCLOTRON_1 A7 //haut gauche
#define CYCLOTRON_2 A6 //haut droite
#define CYCLOTRON_3 A5 //bas droite
#define CYCLOTRON_4 A4 //bas gauche


//-------------------------------------------------------
//-------------------------------------------------------
//FUMEE

#define FUMEE_01 23
#define FUMEE_VENT 23

#define FUMEE_MAX_ON 5000
#define FUMEE_VENT_ON 2000


//-------------------------------------------------------
//-------------------------------------------------------
//PROTON GUN BOX

//BOX
#define PROTONGUN_ACTIVATE_GUN_SWITCH  52
#define PROTONGUN_ACTIVATE_PACK_SWITCH 46
#define PROTONGUN_INTENSITY_SWITCH    50
#define PROTONGUN_ACTIVATE_BUTTON     48
//END GUN
#define PROTONGUN_REDGUN_BUTTON        0

//LED
#define PROTONGUN_WHITELED_FLASHING    42


//-------------------------------------------------------
//-------------------------------------------------------
//SEQUENCE POWER LEVEL INDICATOR ( GUN )

#define PROTONGUN_BARREL_01 53 
#define PROTONGUN_BARREL_02 51
#define PROTONGUN_BARREL_03 49
#define PROTONGUN_BARREL_04 47
#define PROTONGUN_BARREL_05 45
#define PROTONGUN_BARREL_06 43
#define PROTONGUN_BARREL_07 41
#define PROTONGUN_BARREL_08 39
#define PROTONGUN_BARREL_09 37
#define PROTONGUN_BARREL_10 35
/*#define PROTONGUN_BARREL_11 43
#define PROTONGUN_BARREL_12 45
#define PROTONGUN_BARREL_13 47
#define PROTONGUN_BARREL_14 48
#define PROTONGUN_BARREL_15 51
#define PROTONGUN_BARREL_16 53*/

#define PROTONGUN_BARREL_MIN 0
#define PROTONGUN_BARREL_MAX 10
