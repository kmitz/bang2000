
//enum {UN, DEUX, TROIS, QUATRE};
//enum {HAUT, BAS, GAUCHE, DROITE};
export const LARGEUR = 1024;
export const LONGUEUR = 1280;
export const TBALLE = 400;
export const VBALLE = 10;
export const VX = 3;
export const VY = 3;
export const REFRESH_TIME = 10;
export const DEGATS = 20;
export const VIE = 100;
export const _HAUT = 1;
export const _BAS = 2;
export const _GAUCHE = 3;
export const _DROITE = 4;
export const _DEAD = 5;
export const _NB_TYPE_BONUS = 8;
export const _NB_TIR_BONUS = 5;
export const _NB_OBSTACLES = 2;

export const _VITESSE_PLUS = 1;
export const _VITESSE_MOINS = 2;
export const _VIE_PLUS = 3;
export const _VIE_MOINS = 4;
export const _VITESSE_BALLE_PLUS = 5;
export const _VITESSE_BALLE_MOINS = 6;
export const _BONUS_FREEZE = 7;
export const _BONUS_BLITZ = 8;

export const _VX_BLITZ = 10;
export const _VY_BLITZ = 10;
export const _VBALLE_BLITZ = 20;
export const _TBALLE_BLITZ = 200;

export const _VX_FREEZE = 1;
export const _VY_FREEZE = 1;
export const _VBALLE_FREEZE = 2;
export const _TBALLE_FREEZE = 1000;

export const PLAYER_0 = 0;
export const PLAYER_1 = 1;
export const PLAYER_2 = 2;
export const PLAYER_3 = 3;

export const player_sprites = {
	"HAUT" : {
        src : 'assets/Jhaut.bmp',
        width : 33,
        height : 94
	},
	"BAS" : {
        src : 'assets/Jbas.bmp',
        width : 33,
        height : 94
      },
	"GAUCHE" : {
        src : 'assets/Jgauche.bmp',
        width : 55,
        height : 94
      },
	"DROITE" : {
        src : 'assets/Jdroite.bmp',
        width : 55,
        height : 94
      },
    "DEAD" : {
        src : 'assets/Jdead.bmp',
        width : 94,
        height : 94
      }, 
};

export const balle_sprites = {
	"HORIZONTALE" : {
		src : "assets/balleH.bmp"
	},
	"VERTICALE" : {
		src : "assets/balleV.bmp"
	}
}