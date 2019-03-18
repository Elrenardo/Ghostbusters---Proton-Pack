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
#define AUDIO_RX 13 //port
#define AUDIO_TX 12 //port
#define AUDIO_PORT_INIT 9600 //Port init audio card

//Audio Position list .mp3 dans la carte SD
#define AUDIO_PLAY_PACK_ON    2
#define AUDIO_PLAY_PACK_VENT  8
#define AUDIO_PLAY_PACK_OFF   4
#define AUDIO_PLAY_GUN_ON     6
#define AUDIO_PLAY_GUN_STREAM 7
#define AUDIO_PLAY_GUN_OFF    2
#define AUDIO_PLAY_GUN_SWITCH 5
#define AUDIO_PLAY_FUMEE      3


//-------------------------------------------------------
//-------------------------------------------------------
//POWER CELL

#define POWERCELL_01 22
#define POWERCELL_02 24
#define POWERCELL_03 26
#define POWERCELL_04 28
#define POWERCELL_05 30
#define POWERCELL_06 32
#define POWERCELL_07 34
#define POWERCELL_08 36
#define POWERCELL_09 38
#define POWERCELL_10 40
#define POWERCELL_11 42
#define POWERCELL_12 44
#define POWERCELL_13 46
#define POWERCELL_14 48
#define POWERCELL_15 50


//-------------------------------------------------------
//-------------------------------------------------------
//CYCLOTRON

#define CYCLOTRON_1 47 //haut gauche
#define CYCLOTRON_2 49 //haut droite
#define CYCLOTRON_3 51  //bas droite
#define CYCLOTRON_4 53  //bas gauche



//-------------------------------------------------------
//-------------------------------------------------------
//PROTON GUN

//BOX
#define PROTONGUN_ACTIVATE_GUN_SWITCH  23
#define PROTONGUN_ACTIVATE_PACK_SWITCH 25
#define PROTONGUN_ACTIVATE_SWITCH      27
#define PROTONGUN_INTENSITY_BUTTON     29

//LED
#define PROTONGUN_REDLED_STATIC     31
#define PROTONGUN_ORANGELED_STATIC  33
#define PROTONGUN_WHITELED_FLASHING 35
#define PROTONGUN_WHITELED_BIP      37
#define PROTONGUN_VENTLED           39

//END GUN
#define PROTONGUN_REDGUN_BUTTON    41
#define PROTONGUN_ORANGEGUN_STATIC 43

//autre
#define PROTONGUN_PLASMA  45

//SEQUENCE POWER LEVEL INDICATOR
#define PROTONGUN_BARREL_01 A0
#define PROTONGUN_BARREL_02 A1
#define PROTONGUN_BARREL_03 A2
#define PROTONGUN_BARREL_04 A3
#define PROTONGUN_BARREL_05 A4
#define PROTONGUN_BARREL_06 A5
#define PROTONGUN_BARREL_07 A6
#define PROTONGUN_BARREL_08 A7
#define PROTONGUN_BARREL_09 A8
#define PROTONGUN_BARREL_10 A9
#define PROTONGUN_BARREL_11 A10
#define PROTONGUN_BARREL_12 A11
#define PROTONGUN_BARREL_13 A12
#define PROTONGUN_BARREL_14 A13
#define PROTONGUN_BARREL_15 A14
#define PROTONGUN_BARREL_16 A15

#define PROTONGUN_BARREL_MIN 0
#define PROTONGUN_BARREL_MAX 16



//-------------------------------------------------------
//-------------------------------------------------------
//FUMEE

#define FUMEE_01 11
#define FUMEE_VENT 10

#define FUMEE_MAX_ON 5000
#define FUMEE_VENT_ON 2000
