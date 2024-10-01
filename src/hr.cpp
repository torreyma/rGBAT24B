
#include <Rcpp.h>

using namespace Rcpp;

#if defined(WIN32)
#define ROLE __declspec(dllimport) __stdcall
#elif defined(x64)
#define ROLE __declspec(dllimport) __stdcall
#elif defined(__linux__)
#define ROLE __stdcall
#endif

#include <GMCgeo.h>
#include <pac.h>
#include <cstring>
#include <cstdlib>

// [[Rcpp::export]]
std::string HR() {
	
	//setenv("GEOFILES", "/home/dynohub/version-24b_24.2/fls/", 1); // Overwrite it
	// Get HOME environment variable:
	//char* home_path = getenv("HOME");
	// concat HOME path with path to geosupport files:
	//char* geo_path = strcat (home_path, "/version-24b_24.2/fls/"); 
	// Set GEOFILES variable 
	//setenv("GEOFILES", geo_path, 1); 

	union {
        C_WA1 wa1;
        char cwa1[sizeof(C_WA1)];
      } uwa1;
	  
	char cwa2fhr[5000];
	 
    memset(uwa1.cwa1, ' ', sizeof(C_WA1));
	memcpy(uwa1.wa1.input.func_code, "HR", 2);
	uwa1.wa1.input.platform_ind = 'C';
	
	
	memcpy(uwa1.wa1.input.zipin, "10013", 5);
	memcpy(uwa1.wa1.input.hse_nbr_disp, "125", 3); 
	memcpy(uwa1.wa1.input.sti[0].Street_name, "WORTH STREET", 12); 

	geo(uwa1.cwa1, cwa2fhr);

	std::string xxx;
    xxx = cwa2fhr;
	//std::string xxx2 = xxx.substr (14,4);
	std::string xxx2 = xxx.substr (0,50);
	
	return xxx2;
	
}





