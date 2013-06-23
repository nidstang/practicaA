#include "logic.h"
#include "functions.h"

// Establecemos la l�gica del programa.
void logic( World& world )
{
	//creo el reloj del juego
	buildTime(world.time);

	//Control de los estados del teclado
	switch(world.states.playerStates) {
	case TOLEFT:
		if(world.ship.position.x >= 0)
		{
			world.ship.position.x -= spaceMove(world.lastTime);
		}

		world.states.playerStates = NONE;

		break;

	case TORIGTH:
		if((world.ship.position.x + world.ship.width) <= 500)
		{
			world.ship.position.x += spaceMove(world.lastTime);
		}

		world.states.playerStates = NONE;

		break;

	}

	//Control de los estados de la pelota

	if(world.states.gameStates == START) {
		moveBall(world.ball, world.states, world.lastTime);

		if(shockWall(world.ball, world.wall))
		{
			if(world.wall == Walls::RIGHT) {
				world.states.ballStatesX = TOLEFT;


			}
			else if(world.wall == Walls::LEFT) {
				world.states.ballStatesX = TORIGTH;
			}
			else if(world.wall == Walls::TOP) {
				world.states.ballStatesY = TODOWN;
			}
		}
	
	}

	/*if(world.states.stateMoveLeft)
	{
		if(world.ship.position.x > 0)
		{
			world.ship.position.x -= spaceMove(world.lastTime);
		}

		world.states.stateMoveLeft = false;
	}
	else if(world.states.stateMoveRight)
	{
		if((world.ship.position.x + world.ship.width) < 500)
		{
			world.ship.position.x += spaceMove(world.lastTime);
		}

		world.states.stateMoveRight = false;
	}

	if(!world.states.stateStartGame)
	{
		world.ball.position.x = world.ship.position.x + (world.ship.width / 2);
	}
	else
	{
		moveBall(world.ball, world.states, world.lastTime);

		if(shockWall(world.ball, world.wall))
		{

			if(world.wall == Walls::RIGHT || world.wall == Walls::LEFT)
			{
				if(world.states.stateBallDirectionX)
				{
					world.states.stateBallDirectionX = false;
				}
				else
				{
					world.states.stateBallDirectionX = true;
				}
			}
			else if(world.wall == Walls::TOP)
			{
				world.states.stateBallDirectionY = false;
			}
			else
			{
				world.states.stateGameOver = true;
			}
		}
	}*/

	
	/*setSquareIncludesBall(world.ball, world.includesBall);

	if(checkCollision(world.includesBall, world.ship) || checkCollision(world.includesBall, world.prueba))
	{
		world.states.stateBallDirectionY = true;
	}*/



	getLastTime(world);
}