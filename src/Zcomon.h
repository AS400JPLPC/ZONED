#ifndef	indacteur
#define	indacteur

#define   ZONED_OK	0  	///  OK
#define   ZONED_BAD	22	///  DCML_NUM_BAD_NUMERIC
#define   ZONED_OVR	33	///  DCML_NUM_OVERFLOW
#define   ZONED_UND	66	///  DCML_NUM_UNDERFLOW
#define   ZONED_DIV	99	///  DCML_NUM_DIVIDE_ZERO


#define   LT       05       ///  inferieur
#define   EQ       10       ///  egal
#define   GT       15       ///  superieur 

#define NAMEOF(variable) ((void)variable, #variable)


#define   DeLiMiTaTioN		'~'		///  caractère de délimitation
/// use direct char* for sql buffer 


#endif
