#ifndef UTILS_H
#define UTILS_H


//================================
// INCLUDES
//================================

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


//================================
// MACROS
//================================

#define WHERE __FILE__, __func__, __LINE__
#define OHNO ohno(WHERE)
#define PANIC panic(WHERE)


//================================
// EXTERNAL VARIABLES
//================================

extern int errno;


//================================
// PROTOTYPES
//================================

/**
 * @brief			Wrapper for malloc with error handling
 *
 * @details			Calls malloc, uses function panic() if something
 *					goes wrong.
 * 
 * @param size		Size in bytes of memory to be allocated
 * @param file		File that called this function
 * @param function	Function that called this function
 * @param line		Code line that called this function
 * @return void*	Pointer to allocated memory space
 */
void* smalloc(	size_t size,
				char* file,
				const char* function,
				int line);

/**
 * @brief			Wrapper for calloc with error handling
 * 
 * @details			Calls calloc, uses function panic() if something
 *					goes wrong.
 * @param nitems	Number of elements to be allocated
 * @param size		Size in bytes of elements to be allocated
 * @param file		File that called this function
 * @param function	Function that called this function
 * @param line		Code line that called this function
 * @return void*	Pointer to allocated memory space
 */
void* scalloc(	size_t nitems,
				size_t size,
				char* file,
				const char* function,
				int line);

/**
 * @brief		Wrapper for free that nulls the freed pointer
 *
 * @param ptr	Pointer to memory area to be freed
 */
void sfree(void*);

/**
 * @brief			Shows an error message
 *
 * @details			The macro "OHNO" is expanded into
 *					"ohno(__FILE__, __func__, __LINE__)".
 * 
 * @param file		File where error occurred
 * @param function	Function where error occurred
 * @param line		Number of line which called the function
 */
void ohno(	char* file,
			const char* function,
			int line);

/**
 * @brief			Shows an error message and exits
 *
 * @details			The macro "OHNO" is expanded into
 *					"ohno(__FILE__, __func__, __LINE__)".
 * 
 * @param file		File where error occurred
 * @param function	Function where error occurred
 * @param line		Number of line which called the function
 */
void panic(	char* file,
			const char* function,
			int line);

#endif	// UTILS_H
