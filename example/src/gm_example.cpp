#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>

using namespace GarrysMod::Lua;

/*

require( "example" );

MsgN( TestFunction() );

MsgN( TestFunction( 24.75 ) );

*/

int MyExampleFunction( lua_State* state )
{
	if ( LUA->IsType( 1, Type::NUMBER ) )
	{
		char strOut[512];
		float fNumber = LUA->GetNumber( 1 );
		sprintf( strOut, "Thanks for the number - I love %f!!", fNumber );
		LUA->PushString( strOut );
		return 1;
	}

	LUA->PushString( "This string is returned" );
	return 1;
}


//
// Called when you module is opened
//
GMOD_MODULE_OPEN()
{
	//
	// Set Global[ "TextFunction" ] = MyExampleFunction
	//
	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );	// Push global table
	LUA->PushString( "TestFunction" );					// Push Name
	LUA->PushCFunction( MyExampleFunction );			// Push function
	LUA->SetTable( -3 );								// Set the table 

	return 0;
}

//
// Called when your module is closed
//
GMOD_MODULE_CLOSE()
{
	return 0;
}