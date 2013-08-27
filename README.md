gmod-module-base
================

Technically everything you need is in include.

Example contains an example project. Running BuildProjects.bat requires premake4 (http://industriousone.com/premake).

The generated dlls should be placed in

garrysmod/lua/bin/

They should also be named appropriately:

<table>
  <tr>
    <td>gmsv_example_win32.dll</td><td>serverside on windows</td><td>require( 'example' )</td>
  </tr>
  <tr>
    <td>gmsv_example_linux.dll</td><td>serverside on linux</td><td>require( 'example' )</td>
  </tr>
  <tr>
    <td>gmsv_example_osx.dll</td><td>serverside on osx</td><td>require( 'example' )</td>
  </tr>
  <tr><td></td><td></td><td></td></tr>
  <tr>
    <td>gmcl_nutsack_win32.dll</td><td>clientside on windows</td><td>require( 'nutsack' )</td>
  </tr>
  <tr>
    <td>gmcl_example_osx.dll</td><td>clientside on osx</td><td>require( 'example' )</td>
  </tr>
</table>
