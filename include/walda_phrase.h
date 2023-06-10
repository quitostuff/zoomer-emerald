#ifndef GUARD_WALDA_PHRASE_H
#define GUARD_WALDA_PHRASE_H

#define WALDA_PHRASE_LENGTH 15
#define PASSWORD_LENGTH 10       //what if i just dump the password functions and stuff in the walda files

u16 TryBufferWaldaPhrase(void);
void DoWaldaNamingScreen(void);
u16 TryGetWallpaperWithWaldaPhrase(void);

//sure let's copy paste the walda functions here
u16 TryBufferPassword(void);
void DoPasswordScreen(void);
u16 TryGiveMonWithPassword(void);

#endif // GUARD_WALDA_PHRASE_H
