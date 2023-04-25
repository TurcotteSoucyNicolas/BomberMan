#pragma once
#include <SDL.h>
class Input
{
public:
	/// <summary>
	/// change les valeur des boolean en fonction des touche qui sont press
	/// </summary>
	void CheckInput();
	/// <summary>
	/// retourne si la fleche du haut est press
	/// </summary>
	/// <returns>true is la touche up est enfoncer</returns>
	bool GetUp() { return Up; }
	/// <summary>
	/// retourne si la fleche du bas est press
	/// </summary>
	/// <returns>true is la touche down est enfoncer</returns>
	bool GetDown() { return Down; }
	/// <summary>
	/// retourne si la fleche de gauche est press
	/// </summary>
	/// <returns>true is la touche left est enfoncer</returns>
	bool GetLeft() { return Left; }
	/// <summary>
	/// retourne si la fleche de droit est press
	/// </summary>
	/// <returns>true is la touche right est enfoncer</returns>
	bool GetRight() { return Right; }
	/// <summary>
	/// retourne la valeur du boolean havemove qui permet de savoir si le personnave a bouger
	/// </summary>
	/// <returns>retourne true si le joueur a bouger</returns>
	bool GetHaveMove() { return HaveMove; }
	/// <summary>
	/// retourne si la espave est press
	/// </summary>
	/// <returns>true is la touche Space est enfoncer</returns>
	bool GetSpace() { return Space; }
	/// <summary>
	/// retoure si la touche espace a éte enfoncer
	/// </summary>
	/// <returns>retourne true si la touche a été enfoncer</returns>
	bool GetSpaceIsPress() { return SpaceIsPress; }
	/// <summary>
	/// set la valeur true a la variable SpaceIsPress
	/// </summary>
	void SetSpaceIsPress() { SpaceIsPress = true; }
	/// <summary>
	/// set la valeur true a la variable HaveMove
	/// </summary>
	void SetMove() { HaveMove = true; }
private:
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;
	bool Space = false;
	bool SpaceIsPress = false;
	bool HaveMove = false;
	};

