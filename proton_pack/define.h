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
#define AUDIO_RX 10 //port
#define AUDIO_TX 11 //port
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

#define POWERCELL_01 0
#define POWERCELL_02 0
#define POWERCELL_03 0
#define POWERCELL_04 0
#define POWERCELL_05 0
#define POWERCELL_06 0
#define POWERCELL_07 0
#define POWERCELL_08 0
#define POWERCELL_09 0
#define POWERCELL_10 0
#define POWERCELL_11 0
#define POWERCELL_12 0
#define POWERCELL_13 0
#define POWERCELL_14 0
#define POWERCELL_15 0


//-------------------------------------------------------
//-------------------------------------------------------
//CYCLOTRON

#define CYCLOTRON_1 1 //haut gauche
#define CYCLOTRON_2 2 //haut droite
#define CYCLOTRON_3 3 //bas droite
#define CYCLOTRON_4 4 //bas gauche



//-------------------------------------------------------
//-------------------------------------------------------
//PROTON GUN

//BOX
#define PROTONGUN_ACTIVATE_GUN_SWITCH  0
#define PROTONGUN_ACTIVATE_PACK_SWITCH 0
#define PROTONGUN_ACTIVATE_SWITCH      0
#define PROTONGUN_INTENSITY_BUTTON     0

//LED
#define PROTONGUN_REDLED_STATIC     0
#define PROTONGUN_ORANGELED_STATIC  0
#define PROTONGUN_WHITELED_FLASHING 0
#define PROTONGUN_WHITELED_BIP      0
#define PROTONGUN_VENTLED           0

//END GUN
#define PROTONGUN_REDGUN_BUTTON    0
#define PROTONGUN_ORANGEGUN_STATIC 0

//autre
#define PROTONGUN_PLASMA  0

//SEQUENCE POWER LEVEL INDICATOR
#define PROTONGUN_BARREL_01 0
#define PROTONGUN_BARREL_02 0
#define PROTONGUN_BARREL_03 0
#define PROTONGUN_BARREL_04 0
#define PROTONGUN_BARREL_05 0
#define PROTONGUN_BARREL_06 0
#define PROTONGUN_BARREL_07 0
#define PROTONGUN_BARREL_08 0
#define PROTONGUN_BARREL_09 0
#define PROTONGUN_BARREL_10 0
#define PROTONGUN_BARREL_11 0
#define PROTONGUN_BARREL_12 0
#define PROTONGUN_BARREL_13 0
#define PROTONGUN_BARREL_14 0
#define PROTONGUN_BARREL_15 0
#define PROTONGUN_BARREL_16 0
#define PROTONGUN_BARREL_17 0
#define PROTONGUN_BARREL_18 0
#define PROTONGUN_BARREL_19 0
#define PROTONGUN_BARREL_20 0

#define PROTONGUN_BARREL_MIN 0
#define PROTONGUN_BARREL_MAX 20



//-------------------------------------------------------
//-------------------------------------------------------
//FUMEE

#define FUMEE_01 0
#define FUMEE_VENT 0

#define FUMEE_MAX_ON 5000
~define FUMEE_VENT_ON 2000
