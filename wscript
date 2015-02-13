import sys
import moai_env

VERSION = '0.0.1'
APPNAME = 'gwen-moai-test'

top = '.'
out = './_build'


def configure( conf ):
	conf.load( 'compiler_cxx compiler_c' )
	moai_env.setup_moai_env( conf, 'osx', 'debug' )
	moai_env.setup_fmod_env( conf, 'osx', 'debug' )
	conf.env.ARCH  = [ 'i386' ]
	conf.env.CXXFLAGS  = [ '-fno-rtti', '-stdlib=libstdc++', '-g', '-fvisibility=hidden' ]

def options( opt ):
	opt.load( 'compiler_cxx compiler_c' )

def build( bld ):
	bld.recurse( [ 'host-modules', 'freejoy', 'gwen', 'extension', 'SDLHost' ] )
	install_path = 'test'
