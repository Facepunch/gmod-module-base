#include <stdint.h>
#include <string>
#include "GarrysMod/Lua/Interface.h"

/*
	require "MetaTable"
	local x = Create_My_Wrapped_Float( 5 )
	local y = Create_My_Wrapped_Float( 17 )

	print( x, y, x + y )
*/

using namespace GarrysMod::Lua;

static int s_My_Wrapped_Float_TypeId;

struct My_Wrapped_Float
{
	float value;
};

LUA_FUNCTION( Create_My_Wrapped_Float )
{
	float value = static_cast<float>( LUA->CheckNumber( 1 ) );

	My_Wrapped_Float result{ value };
	LUA->PushUserType_Value( result, s_My_Wrapped_Float_TypeId );
	return 1;
}

LUA_FUNCTION( MyStructure_meta_add )
{
	My_Wrapped_Float* pFloat1 = LUA->GetUserType<My_Wrapped_Float>( 1, s_My_Wrapped_Float_TypeId );
	My_Wrapped_Float* pFloat2 = LUA->GetUserType<My_Wrapped_Float>( 2, s_My_Wrapped_Float_TypeId );

	if ( pFloat1 == nullptr )
	{
		LUA->ArgError( 1, "expected My_Wrapped_Float" );
		return 0;
	}

	if ( pFloat2 == nullptr )
	{
		LUA->ArgError( 2, "expected My_Wrapped_Float" );
		return 0;
	}

	My_Wrapped_Float result{ pFloat1->value + pFloat2->value };
	LUA->PushUserType_Value( result, s_My_Wrapped_Float_TypeId );
	return 1;
}

LUA_FUNCTION( MyStructure_meta_tostring )
{
	My_Wrapped_Float* pFloat1 = LUA->GetUserType<My_Wrapped_Float>( 1, s_My_Wrapped_Float_TypeId );

	if ( pFloat1 == nullptr )
	{
		LUA->ArgError( 1, "expected My_Wrapped_Float" );
		return 0;
	}

	std::string strValue = std::to_string( pFloat1->value );
	LUA->PushString( strValue.c_str(), strValue.length() );
	return 1;
}

GMOD_MODULE_OPEN()
{
	s_My_Wrapped_Float_TypeId = LUA->CreateMetaTable( "My_Wrapped_Float" );
		LUA->PushCFunction( MyStructure_meta_add );
		LUA->SetField( -2, "__add" );

		LUA->PushCFunction( MyStructure_meta_tostring );
		LUA->SetField( -2, "__tostring" );
	LUA->Pop();

	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );
		LUA->PushCFunction( Create_My_Wrapped_Float );
		LUA->SetField( -2, "Create_My_Wrapped_Float" );
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}
