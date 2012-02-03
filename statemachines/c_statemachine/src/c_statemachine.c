/*
 * Example code for a very simple statemachine.
 *
 * Used in teaching C programming on embedded systems at EAL
 *
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states { Red, RedYellow, Green, Yellow };
// Event definitions
enum events { Stop, Go, Ready, TICK };

int TS_State = Red;

// forward function declarations
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
void TurnstileSM(int event);
//------------------------------

int main()
{	// By sending hardcoded events to the SM, it is possible to
	// simulate how it works.
    TurnstileSM( Stop );
    TurnstileSM( TICK );
    TurnstileSM( Ready );
    TurnstileSM( TICK );
    TurnstileSM( Go );
    TurnstileSM( TICK );
    TurnstileSM( Ready );
    TurnstileSM( TICK );


    int t;
    for (t=0; t<5; t++) TurnstileSM( TICK );

    /* In an actual system it would look more like this:
     *
     * while (1)
     * {
     * 		event = Input();
     * 		TurnstileSM( event );
     * }
     *
     */
    return 0;
}


/* The SM does not know anything about the system. This way it can be tested on a
 * different C compiler very easily.
 */
void TurnstileSM( int event )
{
    int NextState = TS_State;
    static int TicksCount = 0;

    switch( TS_State )
    {
        case Red:
            switch (event )
            {
                case Stop:
                    NextState = RedYellow;
                    break;
                default:
                    break;
            }
            break;
        case RedYellow:
            switch (event )
            {
                case Ready:
                    NextState = Green;
                    break;
            /*    case TICK:
                	TicksCount++;
                	if (TicksCount > 4)
                	{
                		NextState = LOCKED;
                		TicksCount = 0;
               */ 	}
                	break;

                case Green:
                	switch ( event )
                	{
                	case Go:
                		NextState = Yellow;
                		break;
                	}
             break;

                case Yellow:
                 	switch ( event )
                	     	{
                 	case Ready:
                 	NextState = Red;
              		break;
                	     	}



               break;
                	default:
                    break;
            }
            break;
        default:
            break;
            // The program should never get here !
    }

    if (NextState != TS_State)
    {
        OnExit(TS_State);
        OnEnter(NextState);
        TS_State = NextState;
    }

    Do( TS_State );
}

/* The 3 functions OnEnter, OnExit and Do are were all the fun happens.
 * Theee functions are written specifically for this system, and must be replaced
 * if the SM is used somewhere else - say on an embedded system.
 *
 * For simulating the SM a bunch of printf statements should be put here.
 */
void OnEnter( int State )
{

}

void OnExit( int State)
{

}

void Do( int State)
{
    switch (State)
    {
        case Red:
            printf("STOP!\n");
            break;
        case Green:
            printf("GO!\n");
            break;

        case Yellow:
                    printf("GET READY TO STOP!\n");
                    break;

        case RedYellow:
                    printf("GET READY TO GO!\n");
                    break;


    }
}
