#pragma once
#include <avr/io.h>
#include <eduardino_int_types.hpp>

namespace fsr {

/*ADCSRB*/
constexpr bitFlag_t
bin = mBv(7),
acme = mBv(6),
ipr = mBv(5),
adts2 = mBv(2),
adts1 = mBv(1),
adts0 = mBv(0);

/*ADCSRA*/
constexpr bitFlag_t
aden = mBv(7),
adsc = mBv(6),
adate = mBv(5),
adif = mBv(4),
adie = mBv(3),
adps2 = mBv(2),
adps1 = mBv(1),
adps0 = mBv(0);

/*ADMUX*/
constexpr bitFlag_t
refs1 = mBv(7),
refs0 = mBv(6),
adlar = mBv(5),
refs2 = mBv(4),
mux3 = mBv(3),
mux2 = mBv(2),
mux1 = mBv(1),
mux0 = mBv(0);

/*ACSR*/
constexpr bitFlag_t
acd = mBv(7),
acbg = mBv(6),
aco = mBv(5),
aci = mBv(4),
acie = mBv(3),
acis1 = mBv(1),
acis0 = mBv(0);

/*USICR*/
constexpr bitFlag_t
usisie = mBv(7),
usioie = mBv(6),
usiwm1 = mBv(5),
usiwm0 = mBv(4),
usics1 = mBv(3),
usics0 = mBv(2),
usiclk = mBv(1),
usitc = mBv(0);

/*USISR*/
constexpr bitFlag_t
usisif = mBv(7),
usioif = mBv(6),
usipf = mBv(5),
usidc = mBv(4),
usicnt3 = mBv(3),
usicnt2 = mBv(2),
usicnt1 = mBv(1),
usicnt0 = mBv(0);

/*DIDR0*/
constexpr bitFlag_t
adc0d = mBv(5),
adc2d = mBv(4),
adc3d = mBv(3),
adc1d = mBv(2),
ain1d = mBv(1),
ain0d = mBv(0);

/*PCMSK*/
constexpr bitFlag_t
pcint5 = mBv(5),
pcint4 = mBv(4),
pcint3 = mBv(3),
pcint2 = mBv(2),
pcint1 = mBv(1),
pcint0 = mBv(0);

/*PINB*/
constexpr bitFlag_t
pinb5 = mBv(5),
pinb4 = mBv(4),
pinb3 = mBv(3),
pinb2 = mBv(2),
pinb1 = mBv(1),
pinb0 = mBv(0);

/*DDRB*/
constexpr bitFlag_t
ddb5 = mBv(5),
ddb4 = mBv(4),
ddb3 = mBv(3),
ddb2 = mBv(2),
ddb1 = mBv(1),
ddb0 = mBv(0);

/*PORTB*/
constexpr bitFlag_t
pb5 = mBv(5),
pb4 = mBv(4),
pb3 = mBv(3),
pb2 = mBv(2),
pb1 = mBv(1),
pb0 = mBv(0);

/*EECR*/
constexpr bitFlag_t
eepm1 = mBv(5),
eepm0 = mBv(4),
eerie = mBv(3),
eempe = mBv(2),
eepe = mBv(1),
eere = mBv(0);

/*PRR*/
constexpr bitFlag_t
prtim1 = mBv(3),
prtim0 = mBv(2),
prusi = mBv(1),
pradc = mBv(0);

/*WDTCR*/
constexpr bitFlag_t
wdif = mBv(7),
wdie = mBv(6),
wdp3 = mBv(5),
wdce = mBv(4),
wde = mBv(3),
wdp2 = mBv(2),
wdp1 = mBv(1),
wdp0 = mBv(0);

/*DTPS1*/
constexpr bitFlag_t
dtps11 = mBv(1),
dtps10 = mBv(0);

/*DT1B*/
constexpr bitFlag_t
dt1bh3 = mBv(7),
dt1bh2 = mBv(6),
dt1bh1 = mBv(5),
dt1bh0 = mBv(4),
dt1bl3 = mBv(3),
dt1bl2 = mBv(2),
dt1bl1 = mBv(1),
dt1bl0 = mBv(0);

/*DT1A*/
constexpr bitFlag_t
dt1ah3 = mBv(7),
dt1ah2 = mBv(6),
dt1ah1 = mBv(5),
dt1ah0 = mBv(4),
dt1al3 = mBv(3),
dt1al2 = mBv(2),
dt1al1 = mBv(1),
dt1al0 = mBv(0);

/*CLKPR*/
constexpr bitFlag_t
clkpce = mBv(7),
clkps3 = mBv(3),
clkps2 = mBv(2),
clkps1 = mBv(1),
clkps0 = mBv(0);

/*PLLCSR*/
constexpr bitFlag_t
lsm = mBv(7),
pcke = mBv(2),
plle = mBv(1),
plock = mBv(0);

/*TCCR0A*/
constexpr bitFlag_t
com0a1 = mBv(7),
com0a0 = mBv(6),
com0b1 = mBv(5),
com0b0 = mBv(4),
wgm01 = mBv(1),
wgm00 = mBv(0);

/*GTCCR*/
constexpr bitFlag_t
tsm = mBv(7),
pwm1b = mBv(6),
com1b1 = mBv(5),
com1b0 = mBv(4),
foc1b = mBv(3),
foc1a = mBv(2),
psr1 = mBv(1),
psr0 = mBv(0);

/*TCCR1*/
constexpr bitFlag_t
ctc1 = mBv(7),
pwm1a = mBv(6),
com1a1 = mBv(5),
com1a0 = mBv(4),
cs13 = mBv(3),
cs12 = mBv(2),
cs11 = mBv(1),
cs10 = mBv(0);

/*TCCR0B*/
constexpr bitFlag_t
foc0a = mBv(7),
foc0b = mBv(6),
wgm02 = mBv(3),
cs02 = mBv(2),
cs01 = mBv(1),
cs00 = mBv(0);

/*MCUSR*/
constexpr bitFlag_t
wdrf = mBv(3),
borf = mBv(2),
extrf = mBv(1),
porf = mBv(0);

/*MCUCR*/
constexpr bitFlag_t
bods = mBv(7),
pud = mBv(6),
se = mBv(5),
sm1 = mBv(4),
sm0 = mBv(3),
bodse = mBv(2),
isc01 = mBv(1),
isc00 = mBv(0);

/*SPMCSR*/
constexpr bitFlag_t
rsig = mBv(5),
ctpb = mBv(4),
rflb = mBv(3),
pgwrt = mBv(2),
pgers = mBv(1),
spmen = mBv(0);

/*TIFR*/
constexpr bitFlag_t
ocf1a = mBv(6),
ocf1b = mBv(5),
ocf0a = mBv(4),
ocf0b = mBv(3),
tov1 = mBv(2),
tov0 = mBv(1);

/*TIMSK*/
constexpr bitFlag_t
ocie1a = mBv(6),
ocie1b = mBv(5),
ocie0a = mBv(4),
ocie0b = mBv(3),
toie1 = mBv(2),
toie0 = mBv(1);

/*GIFR*/
constexpr bitFlag_t
intf0 = mBv(6),
pcif = mBv(5);

/*GIMSK*/
constexpr bitFlag_t
int0 = mBv(6),
pcie = mBv(5);

/////////

struct adcsrb_t : public FSRmixin<adcsrb_t> {
  unsigned adts : 3,
                : 2,
           ipr : 1,
           acme : 1,
           bin : 1; } static volatile &adcsrb = (adcsrb_t&)ADCSRB;

struct adcsra_t : public FSRmixin<adcsra_t> {
  unsigned adps : 3,
           adie : 1,
           adif : 1,
           adate : 1,
           adsc : 1,
           aden : 1; } static volatile &adcsra = (adcsra_t&)ADCSRA;

struct admux_t : public FSRmixin<admux_t> {
  unsigned mux : 4,
           refs2 : 1,
           adlar : 1,
           refs : 2; } static volatile &admux = (admux_t&)ADMUX;

struct acsr_t : public FSRmixin<acsr_t> {
  unsigned acis : 2,
                : 1,
           acie : 1,
           aci : 1,
           aco : 1,
           acbg : 1,
           acd : 1; } static volatile &acsr = (acsr_t&)ACSR;

struct usicr_t : public FSRmixin<usicr_t> {
  unsigned usitc : 1,
           usiclk : 1,
           usics : 2,
           usiwm : 2,
           usioie : 1,
           usisie : 1; } static volatile &usicr = (usicr_t&)USICR;

struct usisr_t : public FSRmixin<usisr_t> {
  unsigned usicnt : 4,
           usidc : 1,
           usipf : 1,
           usioif : 1,
           usisif : 1; } static volatile &usisr = (usisr_t&)USISR;

struct didr0_t : public FSRmixin<didr0_t> {
  unsigned ain0d : 1,
           ain1d : 1,
           adc1d : 1,
           adc3d : 1,
           adc2d : 1,
           adc0d : 1; } static volatile &didr0 = (didr0_t&)DIDR0;

struct pcmsk_t : public FSRmixin<pcmsk_t> {
  unsigned pcint : 6; } static volatile &pcmsk = (pcmsk_t&)PCMSK;

struct pinb_t : public FSRmixin<pinb_t> {
  unsigned pinb : 6; } static volatile &pinb = (pinb_t&)PINB;

struct ddrb_t : public FSRmixin<ddrb_t> {
  unsigned ddb : 6; } static volatile &ddrb = (ddrb_t&)DDRB;

struct portb_t : public FSRmixin<portb_t> {
  unsigned pb : 6; } static volatile &portb = (portb_t&)PORTB;

struct eecr_t : public FSRmixin<eecr_t> {
  unsigned eere : 1,
           eepe : 1,
           eempe : 1,
           eerie : 1,
           eepm : 2; } static volatile &eecr = (eecr_t&)EECR;

struct prr_t : public FSRmixin<prr_t> {
  unsigned pradc : 1,
           prusi : 1,
           prtim : 2; } static volatile &prr = (prr_t&)PRR;

struct wdtcr_t : public FSRmixin<wdtcr_t> {
  unsigned wdp : 3,
           wde : 1,
           wdce : 1,
           wdp3 : 1,
           wdie : 1,
           wdif : 1; } static volatile &wdtcr = (wdtcr_t&)WDTCR;

struct dtps1_t : public FSRmixin<dtps1_t> {
  unsigned dtps1 : 2; } static volatile &dtps1 = (dtps1_t&)DTPS1;

struct dt1b_t : public FSRmixin<dt1b_t> {
  unsigned dt1bl : 4,
           dt1bh : 4; } static volatile &dt1b = (dt1b_t&)DT1B;

struct dt1a_t : public FSRmixin<dt1a_t> {
  unsigned dt1al : 4,
           dt1ah : 4; } static volatile &dt1a = (dt1a_t&)DT1A;

struct clkpr_t : public FSRmixin<clkpr_t> {
  unsigned clkps : 4,
                : 3,
           clkpce : 1; } static volatile &clkpr = (clkpr_t&)CLKPR;

struct pllcsr_t : public FSRmixin<pllcsr_t> {
  unsigned plock : 1,
           plle : 1,
           pcke : 1,
                : 4,
           lsm : 1; } static volatile &pllcsr = (pllcsr_t&)PLLCSR;

struct tccr0a_t : public FSRmixin<tccr0a_t> {
  unsigned wgm0 : 2,
                : 2,
           com0b : 2,
           com0a : 2; } static volatile &tccr0a = (tccr0a_t&)TCCR0A;

struct gtccr_t : public FSRmixin<gtccr_t> {
  unsigned psr : 2,
           foc1a : 1,
           foc1b : 1,
           com1b : 2,
           pwm1b : 1,
           tsm : 1; } static volatile &gtccr = (gtccr_t&)GTCCR;

struct tccr1_t : public FSRmixin<tccr1_t> {
  unsigned cs1 : 4,
           com1a : 2,
           pwm1a : 1,
           ctc1 : 1; } static volatile &tccr1 = (tccr1_t&)TCCR1;

struct tccr0b_t : public FSRmixin<tccr0b_t> {
  unsigned cs0 : 3,
           wgm02 : 1,
                : 2,
           foc0b : 1,
           foc0a : 1; } static volatile &tccr0b = (tccr0b_t&)TCCR0B;

struct mcusr_t : public FSRmixin<mcusr_t> {
  unsigned porf : 1,
           extrf : 1,
           borf : 1,
           wdrf : 1; } static volatile &mcusr = (mcusr_t&)MCUSR;

struct mcucr_t : public FSRmixin<mcucr_t> {
  unsigned isc0 : 2,
           bodse : 1,
           sm : 2,
           se : 1,
           pud : 1,
           bods : 1; } static volatile &mcucr = (mcucr_t&)MCUCR;

struct spmcsr_t : public FSRmixin<spmcsr_t> {
  unsigned spmen : 1,
           pgers : 1,
           pgwrt : 1,
           rflb : 1,
           ctpb : 1,
           rsig : 1; } static volatile &spmcsr = (spmcsr_t&)SPMCSR;

struct tifr_t : public FSRmixin<tifr_t> {
  unsigned : 1,
           tov : 2,
           ocf0b : 1,
           ocf0a : 1,
           ocf1b : 1,
           ocf1a : 1; } static volatile &tifr = (tifr_t&)TIFR;

struct timsk_t : public FSRmixin<timsk_t> {
  unsigned : 1,
           toie : 2,
           ocie0b : 1,
           ocie0a : 1,
           ocie1b : 1,
           ocie1a : 1; } static volatile &timsk = (timsk_t&)TIMSK;

struct gifr_t : public FSRmixin<gifr_t> {
  unsigned : 5,
           pcif : 1,
           intf0 : 1; } static volatile &gifr = (gifr_t&)GIFR;

struct gimsk_t : public FSRmixin<gimsk_t> {
  unsigned : 5,
           pcie : 1,
           int0 : 1; } static volatile &gimsk = (gimsk_t&)GIMSK;
/////////

static volatile u16 &adc = ADC;
static volatile u16 &adcw = ADCW;
static volatile u16 &eear = EEAR;

/////////

}
