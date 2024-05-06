/**
 * @file Adaptino.h
 * @author Sam4uk
 * @brief
 *
 * @copyright Copyright (c) 2024
 *
 */
#if !defined(_ADAPTINO_HPP_)
#define _ADAPTINO_HPP_
#define bit_read(value, bit) (((value) >> (bit)) & 01)
#define bit_set(value, bit) ((value) |= (01 << (bit)))
#define bit_clear(value, bit) ((value) &= ~(01 << (bit)))
#define bit_toggle(value, bit) ((value) ^= (01 << (bit)))
#define bit_write(value, bit, bitvalue)                                        \
  ((bitvalue) ? bit_set(value, bit) : bit_clear(value, bit))

/** @todo AVR */
#if 1
#define AREF_REF (0)
#define AVCC_REF (1)
#define IREF_1V1 (2)
#define IREF_2V56 (3)
/**
 * @brief
 * @param reference
 */
#define set_adc_reference(reference)                                           \
  bit_write(ADMUX, REFS1, (reference)&0b10);                                   \
  bit_write(ADMUX, REFS0, (reference)&0b1)

#define ADC_RIGHT (0)
#define ADC_LEFT (1)

#define set_adc_adjust(align) bit_write(ADMUX, ADLAR, align)

#define set_adc_channel(channel)                                               \
  {                                                                            \
    bit_write(ADMUX, MUX0, channel & 1);                                      \
    bit_write(ADMUX, MUX1, channel & 2);                                      \
    bit_write(ADMUX, MUX2, channel & 4);                                      \
    bit_write(ADMUX, MUX3, channel & 8);                                     \
    bit_write(ADMUX, MUX4, channel & 16);                                     \
    bit_write(ADCSRB, MUX5, channel & 32);                                    \
  }
#define adc_enable() bit_set(ADCSRA, ADEN)
#define adc_start() bit_set(ADCSRA, ADSC)
#define adc_autotrigger_on() bit_set(ADCSRA, ADATE)
#define adc_autotrigger_off() bit_clear(ADCSRA, ADATE)
// #define () bit_is_set(ADCSRA,ADIF)
#define adc_intrrupt_enable() bit_set(ADCSRA, ADIE)

#define ADC_PRE_1 (0)
#define ADC_PRE_2 (1)
#define ADC_PRE_4 (2)
#define ADC_PRE_8 (3)
#define ADC_PRE_16 (4)
#define ADC_PRE_32 (5)
#define ADC_PRE_64 (6)
#define ADC_PRE_128 (7)

#define adc_set_prescaler(value)                                               \
  {                                                                            \
    bit_write(ADCSRA, ADPS0, channel & 01);                                    \
    bit_write(ADCSRA, ADPS1, channel & 02);                                    \
    bit_write(ADCSRA, ADPS2, channel & 04);                                    \
  }

#endif

#endif