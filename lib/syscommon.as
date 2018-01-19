* Disassembly by Os9disasm of syscommon.r


 section bss
_errno EXPORT
_os9err EXPORT
_sysret EXPORT
_mtop EXPORT
_stop EXPORT
_stbot EXPORT
memend EXPORT

_stop: rmb 2
_stbot: rmb 2
_mtop: rmb 2
memend: rmb 2

_errno: rmb 2
 endsect

 section code

_os9err: clra   
 std   _errno,y 
* ldd   #-1 
 rts    
_sysret: bcs   _os9err 
 clra   
 clrb   
 rts    

 endsect  

