// constants.h
// -----------------------------------------------------------------------------
// Physical / natural constants shared by all ADCS files.
// Include it with  #include "constants.h"  instead of redefining values locally.
// Units are SI (m, s, kg, T, rad) unless the name says otherwise.
// -----------------------------------------------------------------------------
#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

// ---- Math ------------------------------------------------------------------
constexpr double PI         = 3.14159265358979323846;
constexpr double DEG_TO_RAD = PI / 180.0;   // multiply degrees by this to get radians
constexpr double RAD_TO_DEG = 180.0 / PI;   // multiply radians by this to get degrees

// ---- Fundamental physics ---------------------------------------------------
constexpr double G_CONST         = 6.67430e-11;   // gravitational constant [m^3/(kg s^2)]
constexpr double SPEED_OF_LIGHT  = 299792458.0;   // GPS ranging, downlink wavelength (lambda = c / f) [m/s]
constexpr double BOLTZMANN       = 1.380649e-23;  // downlink link budget, noise power N = k*T*B [J/K]
constexpr double MU_0            = 1.25663706212e-6; // vacuum permeability, magnetorquer coil field [T m/A]
constexpr double STEFAN_BOLTZMANN = 5.670374419e-8; // thermal radiation, panel/battery temperature [W/(m^2 K^4)]

// ---- Earth: gravity and shape ----------------------------------------------
// Gravitational parameter (G * M_earth). Used for the orbital rate
// n = sqrt(MU_EARTH / a^3), which goes into the B-dot gain, and for the
// orbit simulation.
constexpr double MU_EARTH = 3.986004418e14;   // [m^3/s^2]
constexpr double M_EARTH  = 5.9722e24;        // mass [kg]

// WGS-84 ellipsoid: GPS gives positions on this, and imaging / downlink need
// it to convert latitude, longitude, altitude <-> ECEF x, y, z.
constexpr double R_EARTH       = 6378137.0;             // equatorial radius [m]
constexpr double F_EARTH       = 1.0 / 298.257223563;   // flattening [-]
constexpr double R_EARTH_POLAR = R_EARTH * (1.0 - F_EARTH); // polar radius, ~6356752 m [m]
constexpr double E2_EARTH      = F_EARTH * (2.0 - F_EARTH); // eccentricity squared [-]
constexpr double R_EARTH_MEAN  = 6371008.8;             // mean radius, for simple spherical models [m]

constexpr double J2_EARTH = 1.08262668e-3;    // oblateness term, orbit propagation (largest perturbation) [-]
constexpr double G0       = 9.80665;          // standard gravity at the surface [m/s^2]

// Earth's rotation rate. Needed to convert between inertial (ECI) and
// Earth-fixed (ECEF) frames, e.g. GPS data, target locations, ground station.
constexpr double OMEGA_EARTH = 7.2921150e-5;  // [rad/s]

// ---- Earth: magnetic field (used by B-dot and P_Dumping) ---------------------
// Simple dipole model:  |B| ~= B0_EARTH * (R_EARTH / r)^3 * sqrt(1 + 3 sin^2(lat_mag))
// Useful for simulation and for sanity-checking magnetometer readings.
constexpr double B0_EARTH = 3.12e-5;          // equatorial surface field strength [T]
// Tilt of the dipole axis from Earth's spin axis.
constexpr double MAG_DIPOLE_TILT_DEG = 9.4;   // [deg]

// ---- Earth: radiation (sun pointing / power, CSS albedo error) ---------------
// Sunlight reflected off Earth also lights up the coarse sun sensors and can
// pull the sun-vector estimate toward Earth.
constexpr double EARTH_ALBEDO = 0.30;          // average fraction of sunlight reflected [-]
constexpr double EARTH_IR_FLUX = 237.0;        // average Earth infrared emission [W/m^2]

// ---- Sun (sun pointing, eclipse check, power) --------------------------------
constexpr double AU             = 1.495978707e11;  // mean Earth-Sun distance [m]
constexpr double R_SUN          = 6.957e8;         // solar radius, eclipse (umbra/penumbra) geometry [m]
constexpr double MU_SUN         = 1.32712440018e20; // solar gravitational parameter [m^3/s^2]
constexpr double SOLAR_FLUX     = 1361.0;          // solar constant at 1 AU, power estimates [W/m^2]
constexpr double SOLAR_PRESSURE = 4.56e-6;         // radiation pressure at 1 AU, disturbance torque [N/m^2]
// Tilt of Earth's axis relative to its orbit. Needed for the sun-position
// model (sun vector in ECI from the date).
constexpr double OBLIQUITY_ECLIPTIC_DEG = 23.439291; // at J2000 [deg]

// ---- Moon (orbit perturbation, can block the sun / sensors) ------------------
constexpr double MU_MOON = 4.9028e12;          // [m^3/s^2]
constexpr double R_MOON  = 1.7374e6;           // [m]

// ---- Time ------------------------------------------------------------------
constexpr double SECONDS_PER_DAY = 86400.0;            // [s]
constexpr double SIDEREAL_DAY    = 86164.0905;         // one Earth rotation relative to the stars [s]
constexpr double JULIAN_CENTURY  = 36525.0;            // days, used in sun/Earth rotation models [day]
constexpr double JD_J2000        = 2451545.0;          // Julian date of the J2000 epoch (2000-01-01 12:00 TT) [day]

#endif  // MYLIB_CONSTANTS_H
