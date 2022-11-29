#ifndef PLATFORM_TRIMUI_H
#define PLATFORM_TRIMUI_H
#include <tinyalsa/asoundlib.h>
#include <sys/syscall.h>

/*	TRIMUI Key Codes
	BUTTON     GMENU          SDL             NUMERIC   GPIO
	-----------------------------------------------------------------------------
	A          CONFIRM        SDLK_SPACE      32
	B          CANCEL         SDLK_LCTRL      306
	X          MODIFIER       SDLK_LSHIFT     304
	Y          MANUAL         SDLK_LALT       308
	L          SECTION_PREV   SDLK_TAB        9
	R          SECTION_NEXT   SDLK_BACKSPACE  8
	START      SETTINGS       SDLK_RETURN     13
	SELECT     MENU           SDLK_RCTRL      305
	MENU       POWER          SDLK_ESCAPE     27
	UP         UP             SDLK_UP         273
	DOWN       DOWN           SDLK_DOWN       274
	RIGHT      RIGHT          SDLK_RIGHT      275
	LEFT       LEFT           SDLK_LEFT       276
*/

static uint32_t oc_tableT[] = {		// TRIMUI: Removed unstable and duplicate
//	stable LSByte order = 32 , 22 , 12 , 02 , 33 , 23 , 13 , 01 >> 31 , 30 , 20 >> 11 > 21 > 10 >> 00	(03)
	0x00100112, //				// 16MHz lowest for sleep
	0x00200212, //				// 32MHz
	0x00300122, //0x00300122, 0x00300312,	// 48MHz
	0x00400132, //0x00400412, 		// 64MHz
	0x00480222, //				// 72MHz
	0x00500512, //				// 80MHz
	0x00600232, //0x00600322, 0x00600612,	// 96MHz
	0x00700712, //				// 112MHz
	0x00780422, //				// 120MHz
	0x00800332, //0x00800812, 		// 128MHz
	0x00900522, //0x00900912, 		// 144MHz
	0x00a00432, //0x00a00a12, 		// 160MHz
	0x00a80622, //				// 168MHz
	0x00c00532, //0x00c00722, 0x00c00b12,	// 192MHz
	0x00cc1013, //0x00cc1001,		// 204MHz
	0x00d00c12,
	0x00d80822, //0x00d81a02, 0x00d80833, 0x00d80b23, 0x00d81113, 0x00d81101, 0x00d80220, 0x00d80811, 0x00d80521, 0x00d80800,
	0x00e00632, //0x00e00d12,
	0x00e41213, //0x00e41201,
	0x00ea0c23,
	0x00f00922, //0x00f00e12, 0x00f01d02, 0x00f00933, 0x00f01313, 0x00f01301, 0x00f00431, 0x00f00911, 0x00f00410, 0x00f00900,
	0x00fc0d23, //0x00fc1413, 0x00fc1401, 0x00fc0621,
	0x01000732, //0x01000f12, 0x01001f02,
	0x01080a22, //0x01080a33, 0x01081513, 0x01080a11,
	0x010e0e23,
	0x01101012,
	0x01141613, //0x01141601,
	0x01200832, //0x01200b22, 0x01201112, 0x01200b33, 0x01200f23, 0x01201713, 0x01201701, 0x01200230, 0x01200320, 0x01200b11, 0x01200721, 0x01200510,
	0x012c1813,
	0x01301212,
	0x01321023,
	0x01380c22, //0x01380c33, 0x01381913, 0x01381901, 0x01380c11, 0x01380c00,
	0x01400932, //0x01401312,
	0x01441123, //0x01441a13, 0x01441a01, 0x01440821,
	0x01500d22, //0x01501412, 0x01500d33, 0x01501b13, 0x01501b01, 0x01500631, 0x01500d11, 0x01500610, 0x01500d00,
	0x01561223,
	0x015c1c13,
	0x01600a32, //0x01601512,
	0x01680e22, //0x01680e33, 0x01681323, 0x01681d13, 0x01681d01, 0x01680420, 0x01680e11, 0x01680921,
	0x01701612,
	0x01741e13, //0x01741e01,
	0x017a1423,
	0x01800b32, //0x01800f22, 0x01801712, 0x01800f33, 0x01801f13, 0x01801f01, 0x01800731, 0x01800f11,
	0x018c1523,
	0x01901812,
	0x01981022, //0x01981033, 0x01981011,
	0x019e1623,
	0x01a00c32, //0x01a01912,
	0x01b01122, //0x01b01a12, 0x01b01133, 0x01b01723, 0x01b00831, 0x01b01100,
	0x01c00d32, //0x01c01b12,
	0x01c21823,
	0x01c81222, //0x01c81233, 0x01c81211,
	0x01d01c12,
	0x01d41923, //0x01d40c21,
	0x01e00e32, //0x01e01322, 0x01e01d12, 0x01e01333, 0x01e00931,
	0x01e61a23,
	0x01f01e12,
	0x01f81422, //0x01f81433, 0x01f81b23, 0x01f80620, 0x01f81411, 0x01f80d21,
	0x02000f32, //0x02001f12,
	0x020a1c23,
	0x02101522, //0x02101533, 0x02100a31, 0x02101511,
	0x021c1d23,
	0x02201032,
	0x02281622, //0x02281633, 0x02281611,
	0x022e1e23,
	0x02401132, //0x02401733, 0x02401f23,
	0x02581822, //0x02581833,
	0x02601232,
	0x02641021,				// 612MHz
	0x02701922, //0x02701933, 0x02700c31, 0x02701911,
	0x02801332,
	0x02881a22, //0x02881a33, 0x02881a11, 0x02881121,
	0x02a01432, //0x02a01b22, 0x02a01b33,
	0x02b81c22, //0x02b81c33,
	0x02c01532,				// 704MHz MIYOO Default
	0x02d01d22, //0x02d01d33,		// 720MHz TRIMUI Default
	0x02e01632,				// 736MHz
	0x02e81e22, //0x02e81e33,		// 744MHz
	0x03001732, //0x03001f22, 0x03001f33,	// 768MHz
	0x03201832,				// 800MHz
	0x03401932,				// 832MHz
	0x03601a32,				// 864MHz
	0x03801b32,				// 896MHz highest
};

class Trimui : public Platform {
private:
	int32_t	memdev = 0;
	volatile uint32_t *mem;
	volatile uint32_t *mem2;

	int	trimui_volume;
	int	trimui_brightness;

	uint32_t lcdHTpatch = 0x03e70025;
	uint32_t lcdHTdefault = 0x04640025;
	uint32_t tickBattery = 0;

	uint32_t USBHeadPhoneFlag = 0;

#define JSONKEYSMAX 6
#define JSONSTRSIZE 16
#define	JSON_VOLUME 0
#define	JSON_BRIGHTNESS 4
	const char	jsonkeyname[JSONKEYSMAX][JSONSTRSIZE] = {
			"\"vol\"","\"keymap\"","\"mute\"","\"bgmvol\"","\"brightness\"","\"language\""};
	char		jsonvalue[JSONKEYSMAX][JSONSTRSIZE] = {
			"20","0","1","0","10","\"en.lang\""};
	uint32_t	writejsonflag = 0;
	
	//
	//	Trim Strings for reading json
	//
	char* trimstr(char* str, uint32_t first) {
		char *firstchar, *firstlastchar, *lastfirstchar, *lastchar;
		uint32_t i;
		
		firstchar = firstlastchar = lastfirstchar = lastchar = 0;
		
		for (i=0; i<strlen(str); i++) {
			if ((str[i]!='\r')&&(str[i]!='\n')&&(str[i]!=' ')&&(str[i]!='\t')&&
			    (str[i]!='{')&&(str[i]!='}')&&(str[i]!=',')) {
				if (!firstchar) {
					firstchar = &str[i];
					lastfirstchar = &str[i];
				}
				lastchar = &str[i];
				if (i) {
					if ((str[i-1]=='\r')||(str[i-1]=='\n')||(str[i-1]==' ')||(str[i-1]=='\t')||
					    (str[i-1]=='{')||(str[i-1]=='}')||(str[i-1]==',')) {
						lastfirstchar = &str[i];
					}
				}
			} else {
				if (!firstlastchar) {
					firstlastchar = lastchar;
				}
			}
		}
		if (first) {
			lastfirstchar = firstchar;
			lastchar = firstlastchar;
		}
		if (lastchar) {
			lastchar[1] = 0;
		}
		if (lastfirstchar) return lastfirstchar;
		return 0;
	}
	
	//
	//	Read system.json
	//
	void readJson(void) {
		FILE *fp;
		char key[256];
		char val[256];
		char *keyptr, *valptr;
		int f;
		uint32_t i;
		
		fp = fopen("/mnt/system.json", "r");
		if (fp != NULL) {
			key[0] = 0; val[0] = 0;
			while ((f = fscanf(fp, "%255[^:]:%255[^\n]\n", key, val)) != EOF) {
				if (!f) { if (fscanf(fp,"%*[^\n]\n") == EOF) break; else continue; }
				if (!(keyptr = trimstr(key,0))) continue;
				if (!(valptr = trimstr(val,1))) { val[0] = 0; valptr = val; }
				for (i=0; i<JSONKEYSMAX; i++) {
					if (!strcmp(keyptr,&jsonkeyname[i][0])) {
						strncpy(&jsonvalue[i][0],valptr,JSONSTRSIZE-1);
						break;
					}
				}
				key[0] = 0; val[0] = 0;
			}
			fclose(fp);
		}
	}
	
	//
	//	Write system.json
	//
	void writeJson(void) {
		FILE *fp;
		uint32_t i;
		
		fp = fopen("/mnt/system.json", "w");
		if (fp != NULL) {
			fputs("{\n\t",fp);
			for (i=0; i<JSONKEYSMAX; i++) {
				fputs(&jsonkeyname[i][0],fp);
				fputs(":\t",fp);
				fputs(&jsonvalue[i][0],fp);
				if (i != JSONKEYSMAX-1) {
					fputs(",\n\t",fp);
				} else {
					fputs("\n}",fp);
				}
			}
			fflush(fp);
			fsync(fileno(fp));
			fclose(fp);
		}
	}
	
	//
	//	Get numeric value from json
	//
	uint32_t getValue(uint32_t key) {
		if (key < JSONKEYSMAX-1) {	// except language
			return (uint32_t)atoi(&jsonvalue[key][0]);
		} else return 0;
	}
	
	//
	//	Set numeric value to json
	//
	void setValue(uint32_t key,uint32_t val) {
		if (key < JSONKEYSMAX-1) {	// except language
			snprintf(&jsonvalue[key][0],JSONSTRSIZE,"%d",val);
		}
	}

	//
	//	Check connect USB Headphones
	//
	void USB_HeadPhone_check() {
		if (access("/dev/dsp1", F_OK) == 0) {
			if (USBHeadPhoneFlag == 0) {
				setenv("AUDIODEV", "/dev/dsp1", 1);
				USBHeadPhoneFlag = 1;
				setVolume(gmenu2x->confInt["globalVolume"]);
				INFO("Sound Output: USB HeadPhone");
			}
		} else {
			if (USBHeadPhoneFlag == 1) {
				setenv("AUDIODEV", "/dev/dsp", 1);
				USBHeadPhoneFlag = 0;
				setVolume(gmenu2x->confInt["globalVolume"]);
				INFO("Sound Output: Internal Speaker");
			}
		}
	}

public:
	Trimui(GMenu2X *gmenu2x) : Platform(gmenu2x) {
		INFO("Trimui");
	};

	void hwDeinit() {
		if (memdev > 0) {
			close(memdev);
		}
	}

	void hwDeinit2() {
		writejsonflag = 0;
	}

	int16_t getBatteryLevel() {
		int val = -1;
		FILE *f = fopen("/sys/devices/soc/1c23400.battery/adc", "r");
		if (f != NULL) {
			fscanf(f, "%i", &val);
			fclose(f);
		}
		return val;
	}

	uint8_t getBatteryStatus(int32_t val, int32_t min, int32_t max) {
		if (val == -1) return 6; // charging
		if (val > 47) return 5; // 100%
		if (val > 45) return 4; // 80%
		if (val > 43) return 3; // 55%
		if (val > 41) return 2; // 30%
		if (val > 40) return 1; // 15%
		return 0; // 0% :(
	}

	void set_gpiokeys(const char* filename) {
		int fd = open(filename, O_RDONLY | O_CLOEXEC);
		if (fd > 0) {
			syscall(__NR_delete_module, "gpio_keys_polled", O_NONBLOCK | O_EXCL);
			syscall(__NR_finit_module, fd, "", 0);
			close(fd);
		}
	}

	void hwInit() {
		cpu_menu = 720;
		cpu_link = 720;
		cpu_max = 896;
		cpu_min = 16;
		cpu_step = 8;
		opk = "";	//"trimui";

		w = 320;
		h = 240;
		batteryStatus = getBatteryStatus(getBatteryLevel(), 0, 0);

//		system("mount -o remount,async /mnt/SDCARD");
		set_gpiokeys("./gpio_keys_polled_trimui.ko");

		memdev = open("/dev/mem", O_RDWR);
		if (memdev > 0) {
			mem  = (uint32_t*)mmap(0, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, memdev, 0x01c20000);
			mem2 = (uint32_t*)mmap(0, 0x1000, PROT_READ | PROT_WRITE, MAP_SHARED, memdev, 0x01c0c000);
			if ((mem == MAP_FAILED) || (mem2 == MAP_FAILED)) {
				ERROR("Could not mmap hardware registers!");
				close(memdev);
			} else {
			//lcd init
			if ((mem[0x0890 >> 2] & 1) != 0) { mem[0x0890 >> 2] = mem[0x0890 >> 2] & 0xF0FFFFFF | 0x03000000; }
			}
		} else {
			WARNING("Could not open /dev/mem");
		}
	}

	void hwInit2() {
		readJson();
		writejsonflag = 1;
		trimui_volume = getValue(JSON_VOLUME);
		trimui_brightness = getValue(JSON_BRIGHTNESS);
		gmenu2x->confInt["globalVolume"] = trimui_volume * 5;
		USB_HeadPhone_check();
		volumeMode = getVolumeMode(trimui_volume);
		int tbri = trimui_brightness * 10;
		if ( tbri == 0 ) tbri = 5;
		gmenu2x->confInt["backlight"] = tbri;
	}

	uint32_t hwCheck(unsigned int interval = 0, void *param = NULL) {
		tickBattery++;
		if (tickBattery > 30) { // update battery level every 30 hwChecks
			tickBattery = 0;
			batteryStatus = getBatteryStatus(getBatteryLevel(), 0, 0);
		}

		USB_HeadPhone_check();
		readJson();
		int tvol = getValue(JSON_VOLUME);
		int tbri = getValue(JSON_BRIGHTNESS);
		if (tvol != trimui_volume) {
			trimui_volume = tvol;
			gmenu2x->confInt["globalVolume"] = tvol * 5;
			volumeMode = getVolumeMode(tvol);
		}
		if (tbri != trimui_brightness) {
			trimui_brightness = tbri;
			tbri *= 10;
			if (tbri == 0) tbri = 5;
			gmenu2x->confInt["backlight"] = tbri;
		}

		return interval;
	}

	void setCPU(uint32_t mhz) {
		uint32_t v;
		uint32_t total = sizeof(oc_tableT) / sizeof(oc_tableT[0]);

		if ((gmenu2x->confInt["cpuChange"]) && (memdev > 0)) {
			for (int x = 0; x < total; x++) {
				if ((oc_tableT[x] >> 16) >= mhz) {
					v = mem[0];
					v &= 0xffff0000;
					v |= (oc_tableT[x] &  0x0000ffff);
					mem[0] = v;
					break;
				}
			}
			INFO("Set CPU clock: %d(0x%08x)", mhz, v);
		}
	}

	void setLCD() {
		if (memdev > 0) {
			uint32_t lcdHT;
			if (gmenu2x->confInt["lcdPatch"]) {
				lcdHT = lcdHTpatch;
			} else {
				lcdHT = lcdHTdefault;
			}
			mem2[0x4c >> 2] = lcdHT;
			INFO("Set LCD HT: %08x", lcdHT);
		}
	}

	void setSDL() {
		if (gmenu2x->confInt["SDLPatch"]) {
			mkdir("/mnt/SDCARD/lib",0777);
			string sdl_copy = "cp -f " + homePath + "/libSDL-1.2.so.0 /mnt/SDCARD/lib";
			system(sdl_copy.c_str());
		} else {
			system("rm -f /mnt/SDCARD/lib/libSDL-1.2.so.0");
		}
	}

	void setBacklight(int val) {
		if ((val)&&(writejsonflag)) {
			int tval = val / 10;
			readJson();
			if (tval != getValue(JSON_BRIGHTNESS)) {
				setValue(JSON_BRIGHTNESS,tval);
				writeJson();
				trimui_brightness = tval;
			}
		}
		if (val) val = 70 + (val / 2);
		uint32_t fd = open("/sys/class/disp/disp/attr/lcdbl", O_WRONLY);
		if (fd) {
			dprintf(fd,"%d",val);
			close(fd);
		}
	}

	int16_t getBacklight() {
		int val = -1;
		FILE *f = fopen("/sys/class/disp/disp/attr/lcdbl", "r");
		if (f != NULL) {
			fscanf(f, "%i", &val);
			fclose(f);
		}
		return ((val -70) *2);
	}

	uint8_t getVolumeMode(uint8_t vol) {
		if (!vol) return VOLUME_MODE_MUTE;
		if (USBHeadPhoneFlag) return VOLUME_MODE_PHONES;
		return VOLUME_MODE_NORMAL;
	}

	void setVolume(int val) {
		struct mixer *mixer;
		struct mixer_ctl *ctl;
#define	MAX_VOL_CTL_NUM	16
		static uint32_t mixer_vol_ctl_numbers = 0;
		static uint8_t mixer_vol_ctl_num[MAX_VOL_CTL_NUM];
		static uint8_t mixer_vol_ctl_val[MAX_VOL_CTL_NUM];
		const char *ctl_name;
		uint32_t i,j;

		if (writejsonflag) {
			int tval = val / 5;
			readJson();
			if (tval != getValue(JSON_VOLUME)) {
				setValue(JSON_VOLUME,tval);
				writeJson();
				trimui_volume = tval;
			}
		}
		if (USBHeadPhoneFlag == 0) {
			// for internal speaker
			mixer_vol_ctl_numbers = 0;
			mixer = mixer_open(0);
			if (mixer != NULL) {
				ctl = mixer_get_ctl(mixer,22);
				if (ctl) {
					mixer_ctl_set_percent(ctl,0,val);
				}
				mixer_close(mixer);
			}
		} else {
			mixer = mixer_open(1);
			if (mixer != NULL) {
				// get ctl numbers/values of Volume if needed
				if (mixer_vol_ctl_numbers == 0) {
					j = mixer_get_num_ctls(mixer);
					for (i=0; i<j; i++) {
						ctl = mixer_get_ctl(mixer,i);
						if (ctl) {
							ctl_name = mixer_ctl_get_name(ctl);
							if ( strstr(ctl_name,"Playback Volume") &&
							    !strstr(ctl_name,"Mic")) {
								mixer_vol_ctl_num[mixer_vol_ctl_numbers] = i;
								mixer_vol_ctl_val[mixer_vol_ctl_numbers] = mixer_ctl_get_num_values(ctl);
								if (++mixer_vol_ctl_numbers >= MAX_VOL_CTL_NUM) break;
							}
						}
					}
					// set 2 and 4 for now if not found
					if (mixer_vol_ctl_numbers == 0) {
						mixer_vol_ctl_numbers = 2;
						mixer_vol_ctl_num[1] = 2;
						mixer_vol_ctl_val[1] = 2;
						mixer_vol_ctl_num[2] = 4;
						mixer_vol_ctl_val[2] = 2;
					}
				}
				// set Volume to USB Headphones/Headset
				for (i=0; i < mixer_vol_ctl_numbers; i++) {
					ctl = mixer_get_ctl(mixer,mixer_vol_ctl_num[i]);
					if (ctl) {
						for (j=0; j<mixer_vol_ctl_val[i]; j++) mixer_ctl_set_percent(ctl,j,val);
					}
				}
				mixer_close(mixer);
			}
		}
		volumeMode = getVolumeMode(val);
	}

	string hwPreLinkLaunch() {
//		system("mount -o remount,sync /mnt/SDCARD");
		return "";
	}
};

#endif
