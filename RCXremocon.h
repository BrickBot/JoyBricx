// RCX remote controller definitions

/*
0xD2 Remote command (LO)
0x01 == Motor C backwards
0x02 == Program 1
0x04 == Program 2
0x08 == Program 3
0x10 == Program 4
0x20 == Program 5
0x40 == Stop program & motors
0x80 == Remote sound
Remote command (HI)
0x01 == PBMessage 1
0x02 == PBMessage 2
0x04 == PBMessage 3
0x08 == Motor A forwards
0x10 == Motor B forwards
0x20 == Motor C forwards
0x40 == Motor A backwards
0x80 == Motor B backwards
*/

#define R_Remo		0xd2	// Remote Control Command
#define R_Stop		0x0000	// Stop program & motors
#define R_LeftFwd	0x0800	// Motor A forwards
#define R_LeftRwd	0x4000	// Motor A backwards
#define R_RightFwd	0x1000	// Motor B forwards
#define R_RightRwd	0x8000	// Motor B backwards
#define R_AuxFwd	0x0001	// Motor C forwards
#define R_AuxRwd	0x2000	// Motor C backwards