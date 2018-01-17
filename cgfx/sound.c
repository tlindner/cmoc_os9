#include <cgfx.h>

/* Sound a tone through the speaker for
 * 'duration' ticks at specified frequency
 * (0-4095) and volume (0-63).  Frequency
 * is not actual, but relative.(<> Hz)
 */
asm error_code
_cgfx_ss_tone(path_id path, int duration, int volume, int frequency)
{
    asm
    {
_Flush	EXTERNAL
_sysret	EXTERNAL
		pshs y
		lbsr _Flush
		lda 9,s get volume
		ldb 7,s get duration
		tfr d,x
		ldy 10,s get frequency
		lda 5,s get path
		ldb #$98 SS.Tone call
		os9 I$SetStt
		lbra	_sysret
	}
} 



