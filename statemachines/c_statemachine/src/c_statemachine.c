/*
 * Example code for a very simple statemachine.
 *
 * Used in teaching C programming on embedded systems at EAL
 *
 */

#include <stdio.h>
#include <stdlib.h>

// State definitions
enum states { LOCKED, UNLOCKED, MAXSTATES };
// Event definitions
enum events { PAYED, PERSONPASSED, TICK, MAXEVENTS };

int TS_State = LOCKED;

// forward function declarations
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
void TurnstileSM(int event);
//------------------------------

int main()
{	// By sending hardcoded events to the SM, it is possible to
	// simulate how it works.
    TurnstileSM( TICK );
    TurnstileSM( PAYED );
    TurnstileSM( PERSONPASSED);
    /* In an actual system it would look more like this:
     *
     * while (1) {
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

    switch( TS_State ) {
        case LOCKED:
            switch (event ) {
                case PAYED:
                    NextState = UNLOCKED;
                    break;

                default:
                    break;
            }
            break;

        case UNLOCKED:
            switch (event) {
                case PERSONPASSED:
            	    NextState = LOCKED;
            	    break;

        default:
            break;
            }
            break;
            // The program should never get here !
    }

    if (NextState != TS_State) {
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
    switch (State) {
        case LOCKED:
            printf("Door is Locked!\n");
            break;
        case UNLOCKED:
            printf("Door is unlocked.\n");
            break;
    }
}

