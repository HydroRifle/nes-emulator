namespace debug
{
	void error(EMUERROR, EMUERRORSUBTYPE, const wchar_t *, const wchar_t *, unsigned long, ...);
	void fatalError(EMUERROR, EMUERRORSUBTYPE, const wchar_t *, const wchar_t *, unsigned long, ...);
}

#define ERROR(TYPE, SUBTYPE, ...) debug::error(TYPE, SUBTYPE, _CRT_WIDE(__FILE__), _CRT_WIDE(__FUNCTION__), __LINE__, __VA_ARGS__, 0)
#define ERROR_IF(E, TYPE, SUBTYPE, ...) if (E) ERROR(TYPE, SUBTYPE, __VA_ARGS__)
#define ERROR_UNLESS(E, TYPE, SUBTYPE, ...) if (!(E)) ERROR(TYPE, SUBTYPE, __VA_ARGS__)

#define FATAL_ERROR(TYPE, SUBTYPE, ...) debug::fatalError(TYPE, SUBTYPE, _CRT_WIDE(__FILE__), _CRT_WIDE(__FUNCTION__), __LINE__, __VA_ARGS__, 0)
#define FATAL_ERROR_IF(E, TYPE, SUBTYPE, ...) if (E) FATAL_ERROR(TYPE, SUBTYPE, __VA_ARGS__)
#define FATAL_ERROR_UNLESS(E, TYPE, SUBTYPE, ...) if (!(E)) FATAL_ERROR(TYPE, SUBTYPE, __VA_ARGS__)