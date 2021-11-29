//
//  PBBase.h
//  PedalBoard
//
//  Created by Qin Hong on 8/3/19.
//

#ifndef PBBase_h
#define PBBase_h

#if defined(__APPLE__)
#include <TargetConditionals.h>
#include <Availability.h>
#endif

/*
 * INLINE and EXTERN
 */

#if !defined(PB_INLINE)
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#define PB_INLINE static inline
#elif defined(__MWERKS__) || defined(__cplusplus)
#define PB_INLINE static inline
#elif defined(__GNUC__)
#define PB_INLINE static __inline__
#elif defined(_MSC_VER)
#define PB_INLINE static __inline
#else
#define PB_INLINE static
#endif
#endif

#define PB_EXPORT __attribute__((visibility ("default")))

#ifdef __cplusplus
#define PB_EXTERN extern "C" PB_EXPORT
#else
#define PB_EXTERN extern PB_EXPORT
#endif

/*
 * OVERLOADABLE
 */

#if __has_extension(attribute_overloadable)
#define PB_OVERLOADABLE __attribute__((__overloadable__))
#else
#define PB_OVERLOADABLE
#endif

//
#define pb_metamacro_foreach_cxt(MACRO, SEP, CONTEXT, ...) \
pb_metamacro_concat(pb_metamacro_foreach_cxt, pb_metamacro_argcount(__VA_ARGS__))(MACRO, SEP, CONTEXT, __VA_ARGS__)

#define pb_metamacro_foreach(MACRO, SEP, ...) \
pb_metamacro_foreach_cxt(pb_metamacro_foreach_iter, SEP, MACRO, __VA_ARGS__)

#define pb_metamacro_foreach_iter(INDEX, MACRO, ARG) MACRO(INDEX, ARG)

#define pb_metamacro_argcount(...) \
pb_metamacro_at(20, __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define pb_metamacro_concat(A, B) \
pb_metamacro_concat_(A, B)

#define pb_metamacro_concat_(A, B) A ## B

#define pb_metamacro_foreach_cxt1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)

#define pb_metamacro_at(N, ...) \
pb_metamacro_concat(pb_metamacro_at, N)(__VA_ARGS__)

#define pb_metamacro_head(...) \
pb_metamacro_head_(__VA_ARGS__, 0)

#define pb_metamacro_head_(FIRST, ...) FIRST

#define pb_metamacro_at0(...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at1(_0, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at2(_0, _1, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at3(_0, _1, _2, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at4(_0, _1, _2, _3, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at5(_0, _1, _2, _3, _4, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at6(_0, _1, _2, _3, _4, _5, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at7(_0, _1, _2, _3, _4, _5, _6, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at8(_0, _1, _2, _3, _4, _5, _6, _7, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at9(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at17(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at18(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at19(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, ...) pb_metamacro_head(__VA_ARGS__)
#define pb_metamacro_at20(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, ...) pb_metamacro_head(__VA_ARGS__)

#define pb_metamacro_foreach_cxt0(MACRO, SEP, CONTEXT)
#define pb_metamacro_foreach_cxt1(MACRO, SEP, CONTEXT, _0) MACRO(0, CONTEXT, _0)
#define pb_metamacro_foreach_cxt2(MACRO, SEP, CONTEXT, _0, _1) \
pb_metamacro_foreach_cxt1(MACRO, SEP, CONTEXT, _0) \
SEP \
MACRO(1, CONTEXT, _1)
#define pb_metamacro_foreach_cxt3(MACRO, SEP, CONTEXT, _0, _1, _2) \
pb_metamacro_foreach_cxt2(MACRO, SEP, CONTEXT, _0, _1) \
SEP \
MACRO(2, CONTEXT, _2)
#define pb_metamacro_foreach_cxt4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
pb_metamacro_foreach_cxt3(MACRO, SEP, CONTEXT, _0, _1, _2) \
SEP \
MACRO(3, CONTEXT, _3)
#define pb_metamacro_foreach_cxt5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
pb_metamacro_foreach_cxt4(MACRO, SEP, CONTEXT, _0, _1, _2, _3) \
SEP \
MACRO(4, CONTEXT, _4)
#define pb_metamacro_foreach_cxt6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
pb_metamacro_foreach_cxt5(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4) \
SEP \
MACRO(5, CONTEXT, _5)
#define pb_metamacro_foreach_cxt7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
pb_metamacro_foreach_cxt6(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5) \
SEP \
MACRO(6, CONTEXT, _6)
#define pb_metamacro_foreach_cxt8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
pb_metamacro_foreach_cxt7(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6) \
SEP \
MACRO(7, CONTEXT, _7)
#define pb_metamacro_foreach_cxt9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
pb_metamacro_foreach_cxt8(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7) \
SEP \
MACRO(8, CONTEXT, _8)
#define pb_metamacro_foreach_cxt10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
pb_metamacro_foreach_cxt9(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8) \
SEP \
MACRO(9, CONTEXT, _9)
#define pb_metamacro_foreach_cxt11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
pb_metamacro_foreach_cxt10(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9) \
SEP \
MACRO(10, CONTEXT, _10)
#define pb_metamacro_foreach_cxt12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
pb_metamacro_foreach_cxt11(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
SEP \
MACRO(11, CONTEXT, _11)
#define pb_metamacro_foreach_cxt13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
pb_metamacro_foreach_cxt12(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) \
SEP \
MACRO(12, CONTEXT, _12)
#define pb_metamacro_foreach_cxt14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
pb_metamacro_foreach_cxt13(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
SEP \
MACRO(13, CONTEXT, _13)
#define pb_metamacro_foreach_cxt15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
pb_metamacro_foreach_cxt14(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) \
SEP \
MACRO(14, CONTEXT, _14)
#define pb_metamacro_foreach_cxt16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
pb_metamacro_foreach_cxt15(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) \
SEP \
MACRO(15, CONTEXT, _15)
#define pb_metamacro_foreach_cxt17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
pb_metamacro_foreach_cxt16(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) \
SEP \
MACRO(16, CONTEXT, _16)
#define pb_metamacro_foreach_cxt18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
pb_metamacro_foreach_cxt17(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) \
SEP \
MACRO(17, CONTEXT, _17)
#define pb_metamacro_foreach_cxt19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
pb_metamacro_foreach_cxt18(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
SEP \
MACRO(18, CONTEXT, _18)
#define pb_metamacro_foreach_cxt20(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) \
pb_metamacro_foreach_cxt19(MACRO, SEP, CONTEXT, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) \
SEP \
MACRO(19, CONTEXT, _19)

#if __OBJC__

// weakify
#define pb_weakify(...) \
pb_keywordify \
pb_metamacro_foreach_cxt(pb_weakify_,, __weak, __VA_ARGS__)

#define pb_weakify_(INDEX, CONTEXT, VAR) \
CONTEXT __typeof__(VAR) pb_metamacro_concat(VAR, _weak_) = (VAR);

// strongify
#define pb_strongify(...) \
pb_keywordify \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
pb_metamacro_foreach(pb_strongify_,, __VA_ARGS__) \
_Pragma("clang diagnostic pop")

#define pb_strongify_(INDEX, VAR) \
__strong __typeof__(VAR) VAR = pb_metamacro_concat(VAR, _weak_);

// unsafeify
#define pb_unsafeify(...) \
pb_keywordify \
pb_metamacro_foreach_cxt(pb_weakify_,, __unsafe_unretained, __VA_ARGS__)

// light weight weakify/strongify/unsafeify without autoreleasepool
#define PB_WEAKIFY(...) \
pb_metamacro_foreach_cxt(pb_weakify_,, __weak, __VA_ARGS__)

#define PB_STRONGIFY(...) \
pb_metamacro_foreach(pb_strongify_,, __VA_ARGS__) \

#define PB_UNSAFEIFY(...) \
pb_metamacro_foreach_cxt(pb_weakify_,, __unsafe_unretained, __VA_ARGS__)

// onExit (aka `defer` in Swift)
typedef void (^pb_cleanupBlock_t)(void);
__unused static void pb_executeCleanupBlock(__strong pb_cleanupBlock_t *block)
{
    (*block)();
}
#define pb_onExit \
pb_keywordify \
__strong pb_cleanupBlock_t pb_metamacro_concat(pb_exitBlock_, __LINE__) __attribute__((cleanup(pb_executeCleanupBlock), unused)) = ^

#if DEBUG
#define pb_keywordify autoreleasepool {}
#else
#define pb_keywordify try {} @catch (...) {}
#endif

// Lock
#define PB_LOCK_TYPE                dispatch_semaphore_t
#define PB_LOCK_DEF(LOCK)           dispatch_semaphore_t LOCK
#define PB_LOCK_INIT(LOCK)          LOCK = dispatch_semaphore_create(1)
#define PB_LOCK(LOCK)               dispatch_semaphore_wait(LOCK, DISPATCH_TIME_FOREVER)
#define PB_TRYLOCK(LOCK)            (dispatch_semaphore_wait(LOCK, DISPATCH_TIME_NOW) == 0 ? YES : NO)
#define PB_UNLOCK(LOCK)             dispatch_semaphore_signal(LOCK)

static inline void _pb_unlock(PB_LOCK_TYPE *lock) {
    PB_UNLOCK(*lock);
}

#define PB_SCOPELOCK(LOCK)          PB_LOCK(LOCK);PB_LOCK_TYPE pb_metamacro_concat(_pb_scope_lock_, __LINE__) __attribute__((cleanup(_pb_unlock), unused)) = LOCK

// Throw an exception with name, reason and info.
#define PB_THROW(NAME, REASON, INFO)                            \
@throw [[NSException alloc] initWithName:NAME reason:REASON userInfo:INFO]

// Generate an NSError
#define PB_ERROR_DOMAIN_DEF(NAME) \
static NSErrorDomain NAME##Domain = @#NAME;

#define PB_ERROR(DOMAIN, CODE, DESC) \
[NSError errorWithDomain:DOMAIN code:CODE userInfo: @{NSLocalizedDescriptionKey: DESC}]

#define PB_ERROR_REASON(DOMAIN, CODE, DESC, REASON) \
[NSError errorWithDomain:DOMAIN code:CODE userInfo: @{NSLocalizedDescriptionKey: DESC, NSLocalizedFailureReasonErrorKey: REASON}]

#endif /*__OBJC__*/

#endif /* PBBase_h */
