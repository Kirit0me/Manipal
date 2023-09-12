#include <stdio.h>

struct Time {
	int hrs;
	int mins;
	int secs;
};

struct Time addTime(struct Time t1, struct Time t2);
struct Time subTime(struct Time t1, struct Time t2);

void main(){
	struct Time t1;
	struct Time t2;
	t1.secs = 30; t1.mins = 30; t1.hrs = 2;
	t2.secs = 50; t2.mins = 10; t2.hrs = 1;
	struct Time addt = addTime(t1, t2);
	struct Time subt = subTime(t1, t2);
	printf( "%d:%d:%d\t%d:%d:%d", addt.hrs, addt.mins, addt.secs, subt.hrs, subt.mins, subt.secs);
}

/*struct Time addTime2(struct Time t1, struct Time t2){
	struct Time t3;
	int total_time = t1.secs + t2.secs + (t1.mins+t2.mins)*60 + (t1.hrs+t2.hrs)*3600;
	int mins = total_time/60;
	t3.secs = total_time%60;
	t3.mins = mins%60;
	t3.hrs = mins/60;
	return t3;
}

struct Time subTime2(struct Time t1, struct Time t2){
	struct Time t3;
	int total_time = t1.secs - t2.secs + (t1.mins-t2.mins)*60 + (t1.hrs-t2.hrs)*3600;
	int mins = total_time/60;
	t3.secs = total_time%60;
	t3.mins = mins%60;
	t3.hrs = mins/60;
	return t3;
}*/

struct Time addTime(struct Time t1, struct Time t2){
	struct Time t3;
	t3.mins = 0;t3.secs = 0;t3.hrs = 0;
	t3.secs += (t1.secs + t2.secs);
	if(t3.secs > 60){
		t3.secs = t3.secs%60;
		t3.mins++;
	}
	t3.mins += (t1.mins + t2.mins);
	if(t3.mins > 60){
		t3.mins = t3.mins%60;
		t3.hrs++;
	}
	t3.hrs += (t1.hrs + t2.hrs);
	return t3;
}

struct Time subTime(struct Time t1, struct Time t2){
	struct Time t3;
	t3.mins = 0;t3.secs = 0;t3.hrs = 0;
	t3.secs += (t1.secs - t2.secs);
	if(t3.secs < 0){
		t3.secs+=60;
		t3.mins--;
	}
	t3.mins += (t1.mins - t2.mins);
	if(t3.mins < 0){
		t3.mins+=60;
		t3.hrs--;
	}
	t3.hrs += (t1.hrs - t2.hrs);
	return t3;
}
