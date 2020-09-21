#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY    (TMIN_APP_TPRI + 1)
#define TRACER_PRIORITY  (TMIN_APP_TPRI + 2)

#ifndef STACK_SIZE
#define STACK_SIZE      (512)
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void game_state_manager_task(intptr_t exinf);
extern void game_state_manager_cyc(intptr_t exinf);
extern void setup_game_task(intptr_t exinf);
extern void setup_game_cyc(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
