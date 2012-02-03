/*
 ============================================================================
 Name        : COCKTAIL_MACHINE.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

enum states
{
  OFF, ALC, NON_ALC, ALL,PASSWORD,
};

enum events
{
  UP, DOWN, SELECT, CANCEL, TICK
};

int placement = OFF;

void
menu(int events);
void
show(int state);

int
main()
{
  menu(UP);


  return 0;
}

void
menu(int event)
{
  int NextState = placement;

  switch (placement)
  {
  case OFF:
    switch (event)
      {
      case UP:
      NextState = ALL;
      break;

      case DOWN:
      NextState = ALC;
      break;

      case SELECT:
      printf("off\n");
      break;

      case CANCEL:
      NextState = OFF;
      break;

      default:
      break;
      }

    break;

  case ALC:
    switch (event)
    {
    case UP:
          NextState = OFF;
          break;

          case DOWN:
          NextState = NON_ALC;
          break;

          case SELECT:
          NextState = PASSWORD;
          break;

          case CANCEL:
          NextState = OFF;
          break;

          default:
          break;
    }
    break;

    case NON_ALC:
    	switch (event)
    	{
    	case UP:
    	NextState = ALC;
    	break;

    	case DOWN:
    		NextState = ALL;
    		break;

    	case SELECT:
    		printf("choose a drink \n");
    		break;

    	 case CANCEL:
    	      NextState = OFF;
    	      break;

    	          default:
    	          break;

    	}
break;
    	case ALL:
    	    	switch (event)
    	    	{
    	    	case UP:
    	    	NextState = NON_ALC;
    	    	break;

    	    	case DOWN:
    	    		NextState = OFF;
    	    		break;

    	    	case SELECT:
    	    		NextState = PASSWORD;
    	    		break;

    	    	 case CANCEL:
    	    	      NextState = OFF;
    	    	      break;

    	    	          default:
    	    	          break;
    	    	}

    break;
  default:
    break;

    }

  if (NextState != placement)
    {
      placement = NextState;
    }

  //show(placement);
}
/*
void
show(int State)
{
  switch (State)
    {
  case GREEN:
    printf("The light is green\n");
    break;
  case YELLOW:
    printf("The light is yellow.\n");
    break;
  case RED:
    printf("The light is red\n");
    break;
  case RED_AND_YELLOW:
    printf("The light is red and yellow\n");
    break;
    }
}
*/
