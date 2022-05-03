#include<stdio.h>
#include<stdbool.h> 
#include<stdint.h>

typedef enum TACCTL_CM {
    TACCTL_CM__NO_CAPTURE,
    TACCTL_CM__RISING_EDGE,
    TACCTL_CM__FALLING_EDGE,
    TACCTL_CM__BOTH_EDGES
} TACCTL_CM;

typedef enum TACCTL_CCIS {
    TACCTL_CCIS__A,
    TACCTL_CCIS__B,
    TACCTL_CCIS__GND,
    TACCTL_CCIS__VCC
} TACCTL_CCIS;

#pragma pack(2)
#ifdef BIG_ENDIAN
typedef struct RegTACCTL {
    TACCTL_CM cm : 2;
    TACCTL_CCIS ccis : 2;
    int scs : 1;
    int scci : 1;
    int __unused : 1;
    bool cap : 1;
    int outmod : 3;
    int ccie : 1;
    int cci : 1;
    int out : 1;
    int cov : 1;
    int ccifg : 1;
} RegTACCTL;
#else 
typedef struct RegTACCTL {
    int ccifg : 1;
    int cov : 1;
    int out : 1;
    int cci : 1;
    int ccie : 1;
    int outmod : 3;
    bool cap : 1;
    int __unused : 1;
    int scci : 1;
    int scs : 1;
    TACCTL_CCIS ccis : 2;
    TACCTL_CM cm : 2;
} RegTACCTL;
#endif 
//RegTACCTL *TACCTL = 0x160;

typedef union {
    RegTACCTL field;
    int16_t raw;
} Tacctl_union;

typedef struct timer {
    int16_t tactl;
    union {
        Tacctl_union tacctl[3];
        struct {
            Tacctl_union tacctl0;
            Tacctl_union tacctl1;
            Tacctl_union tacctl2;
        };
    };
    int16_t __unused[2];
    int16_t tar;
    int16_t taccr[3];
} Timer;

typedef struct msp_registers {
    Timer* timer_a;
    Timer* timer_b;
} msp_registers;

volatile msp_registers* msp_regs {
    .timer_a = 0x0160;
    .timer_b = 0x0220;
}

int main() {
    timer_a ta; 
    // *(int16_t*)&ta.tacctl[1] = 0x12;
    ta.tacctl1.field.outmod = 3;   // tacctl ~= (3 << 6) & 0x0e; 
    ta.tacctl[1].field.ccis = true;
    ta.tacctl[1].field.cm = TACCTL_CM__RISING_EDGE;
    printf("%d\n", ta.tacctl[1].raw);

    printf("%ld\n", sizeof(ta));
    printf("0x%02hx", *(short*)&ta);
}