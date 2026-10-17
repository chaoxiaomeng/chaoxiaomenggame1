//第一章完成于10月17日 
#include<stdio.h>
#include<cstdlib> 
#include<time.h>
    int player_hp;
    int player_hpmax;
	int player_def;
	int player_atk;
	int xianghuo;
	int taopaole=0;
	int guanqia=0; 
    int xuanxiang=1;
   
    


int gongjidam(int atk ,int de){
	int dam=atk-de;
	if(dam>atk*3/10){return dam;
	}else{return atk*3/10;
	}	
}


int taopaoes(int hp_max ,int hp ){
	int es=(hp_max-hp)*100/hp_max;
	if  (es>80){es=80;return es;
	}else if(es<15){es=15; return es; 
	}else{return es;
	} 
}  


struct guaiwu{
     const char *mingzi;
    int m_hp;
    int m_def;
    int m_atk;
    const char *chuchangwenan;
    const char *chanxuewenan;
    const char *zhanbaiwenan;
	const char *taopaoshibaiwenan;
	const char *gongjiwenan;  
 
 };
 
 
struct guaiwu ma1={"缓存饿鬼",50,5,10,
"你看到一堆乱码，在空中缓慢凝聚成实体————缓存饿鬼出现了！\n","缓存饿鬼发出了刺耳的哀嚎\n","乱码散去……深处又传来簌簌的声响\n","缓存饿鬼伸手将手臂代码化，一把抓住你的腿，顷刻炼化,共造成了%d点伤害\n","缓存饿鬼伸手将手臂代码化，数不清的代码进入了你的身体,共造成了%d点伤害\n"};

struct guaiwu mb1={"内存长虫",30,5,15,
"环境中传来了细细簌簌的响声——内存长虫出现了！\n","内存长虫后退，身体蜷缩了两下\n","长虫身体折叠，再也没了声响\n","长虫猛地冲向你，用身体撞击，共造成了%d点伤害\n","长虫追上了你，用身体缠绕住你，死死勒住，共造成了%d点伤害\n" 
};

struct guaiwu mc1={"显卡鬼",40,10,20, 
"热浪扑面而来，风扇狂啸。空气中弥漫着一股‘原价买不到’的怨气，显卡鬼现身了！\n","显卡鬼风扇狂转，画面掉帧到 5 FPS，它正试图用光追渲染你的死状。\n","显卡鬼发出一声刺耳的啸叫，满屏花屏，它的显存终于爆了。\n","你试图切后台逃跑，显卡鬼却瞬间拉满功耗烧断了你的退路！，共造成了%d点伤害\n","显卡鬼瞬间拉满功耗，一股滚烫的热浪如同光追射线般击中了你，共造成了%d点伤害！\n"
};

struct guaiwu md1={"内存鬼",50,15,10,
"系统疯狂弹出‘内存不足’警告，内存鬼从爆满的堆区里一点点蠕动爬了出来。\n"  ,"内存鬼开始疯狂申请新内存，试图用无尽的垃圾数据把你也一起撑爆。\n","内存鬼的引用计数终于归零，它发出一声不甘的叹息，默默等待系统的垃圾回收。\n","你拔腿就跑，但内存鬼引发了内存泄漏，你感觉双腿像灌了铅一样卡顿！共造成了%d点伤害\n","内存鬼猛地吞噬了一大块堆区，你的动作瞬间变得像掉帧一样卡顿，共造成了%d点伤害\n"
};

struct guaiwu me1={"代码夜叉",80,20,15,
"终端屏幕疯狂刷屏，无数报错红字汇聚成一张狰狞的鬼脸——代码夜叉从屎山深处降临了！\n","代码夜叉陷入死循环，狂乱地挥舞着无数分支条件，红色的报错日志铺满了整个屏幕！\n", "“代码夜叉陷入死循环，狂乱地挥舞着无数个 if-else 分支，红色的报错日志铺满了整个屏幕！\n","你试图抛出异常逃跑，却被代码夜叉一个断点死死卡住，动弹不得！共造成了%d点伤害\n","代码夜叉抛出一个致命的 NullPointerException 异常，重重砸在你的身上，共造成了%d点伤害\n"
};

struct zhuangbei{
	const char *zhungbeimingzi;
	const char *zhuangbeimiaoshu;
	const char *zhuangbeixianghuo;
	int zhuangbei_hp;
	int zhuangebei_def;
	int zhuangbei_atk;
	int xiaohaoxianghuo;
	int js;
	int leixing;
	int chiyou;
};
struct zhuangbei  gezishan={"格子衫 ","本猿专属！  生命+30   防御+10","需要香火*20",30,10,0,20,1,0,0, 
};
struct zhuangbei  saibopenzidejiaodao={"赛博喷子的教导","被网安叔叔抓到了，就此从良。  生命+10  防御+10"," 需要香火*17",10,10,0,17,1,0,0,
};
struct zhuangbei  fangtuofaxifashui={"防脱发洗发水","漂肉牌洗发水，怎么洗都有面   生命+20 防御+5 "," 需要香火*15",20,5,0,15,1,0,0,
};
struct zhuangbei  gongpai={"工牌","挂脖子上壮胆，生命+10  防御+5  攻击+8","需要香火*15", 10,5,8,15,1,0,0,
}; 
struct zhuangbei  huwan={"护腕 ","防腱鞘炎，生命+20  防御+8","需要香火*10",20,8,0,10,1,0,0,
};
struct zhuangbei huifuyaoshui={"生命药水","生命+30 "," 需要香火*10",30,0,0,10,3,1,0,
};
struct zhuangbei saibopenzideluyin={"赛博喷子的录音","语句及其狠毒，造成伤害30点","需要香火*15 ",0,0,30,15,2,1,0,
};
struct zhuangbei dnszhurugongji={"DNS注入攻击 ","解析到一半就崩，造成伤害15点"," 需要香火*1 ",0,0,15,1,1,1,0,
};
struct zhuangbei kafeishui={"冷掉的咖啡","泼出去，造成伤害10点"," 需要香火*5 ",0,0,10,5,2,1,0,
}; 
struct zhuangbei fanguangjin={"反光镜","反射不知某位老祖的头顶太阳光，于此同时你感到身体暖暖的，回复生命15点  造成伤害30点","需要香火*15",15,0,30,15,2,1,0,
}; 

struct zhuangbei zongzhuangbei[10]={gezishan,saibopenzidejiaodao,fangtuofaxifashui,gongpai,huwan,huifuyaoshui,dnszhurugongji,saibopenzideluyin,kafeishui,fanguangjin};

 
/*第二座屎山，装备和消耗品可并成一个。 
struct xiaohaopin{
	const char*wenan;
	int xiaohaopin_hp;
	int xiaohaopin_def;
	int xiaohaopin_atk;	
	int xiaohaoxianghuo;
};
struct xiaohaopin huifuyaoshui={"生命药水（生命+30）  需要香火*10 ",30,0,0,-10,
};
struct xiaohaopin saibopenzideluyin={"赛博喷子的录音（语句及其狠毒，造成伤害30点） 需要香火*15 ",0,0,-30,-15, 
};
struct xiaohaopin dnszhurugongji={"DNS注入攻击（解析到一半就崩，造成伤害15点） 需要香火*1 ",0,0,-30,-1,
};
struct xiaohaopin kafeishui={"冷掉的咖啡（泼出去，造成伤害10点） 需要香火*5 ",0,0,-10,-5
}; 
struct xiaohaopin fanguangjin={"反光镜（反射不知某位老祖的头顶太阳光，于此同时你感到身体暖暖的，回复生命15点  造成伤害30点） 需要香火*15",15,0,-15,-15,
}; 
struct xiaohaopin zongxiaohaopin[5] ={huifuyaoshui,dnszhurugongji,saibopenzideluyin,kafeishui,fanguangjin};
*/

int dushuzi(){
	int x;
	while(scanf("%d",&x)!=1){
		while (getchar()!='\n');
		printf("请输入正确数字:\n");
		
	}
	return x; 
	
} 




void zhuangbeifenzhi(struct zhuangbei z){
    player_hpmax+=z.zhuangbei_hp;
	player_hp+=z.zhuangbei_hp;
	player_def+=z.zhuangebei_def;
	player_atk+=z.zhuangbei_atk;
	printf("     =================状态栏=================\n");
	printf("程序员：生命:%d 防御：%d 攻击:%d 香火：%d\n",player_hp , player_def , player_atk,xianghuo);	
		printf("\n");	
}




void shangdian(){
	int huojia[5];
	
	for(int i=0; i<5; i++){
			int chongfu;
		
		do{
		huojia[i]=rand()%10;
		chongfu=0;
		for(int j=0; j<i; j++){
			if(huojia[i]==huojia[j]){
			chongfu=1;
				
			}
			
		}	
			
		}while(chongfu);	
	}
	int zhuangbeirand1=huojia[0];
	int zhuangbeirand2=huojia[1];
	int zhuangbeirand3=huojia[2];
	int zhuangbeirand4=huojia[3];
	int zhuangbeirand5=huojia[4];
  
	do{
	printf("您目前拥有香火：  %d\n",xianghuo);	
	
	printf("===============================================赛博货摊===============================================\n");
	printf("          “要来点什么吗？我这可都是好货。（远方传来模糊的叫卖声）                                        \n");
	printf("                                                                                                          \n");
	printf("1.%s       %s\n",zongzhuangbei[zhuangbeirand1].zhungbeimingzi,zongzhuangbei[zhuangbeirand1].zhuangbeixianghuo);
	printf("描述；     %s\n",zongzhuangbei[zhuangbeirand1].zhuangbeimiaoshu);
	printf("\n");
	printf("2.%s %s\n",zongzhuangbei[zhuangbeirand2].zhungbeimingzi,zongzhuangbei[zhuangbeirand2].zhuangbeixianghuo);
	printf("描述；     %s\n",zongzhuangbei[zhuangbeirand2].zhuangbeimiaoshu);
	printf("\n");
	printf("3.%s      %s\n",zongzhuangbei[zhuangbeirand3].zhungbeimingzi,zongzhuangbei[zhuangbeirand3].zhuangbeixianghuo);
	printf("描述；%s\n",zongzhuangbei[zhuangbeirand3].zhuangbeimiaoshu);
	printf("\n");
	printf("4.%s      %s\n",zongzhuangbei[zhuangbeirand4].zhungbeimingzi,zongzhuangbei[zhuangbeirand4].zhuangbeixianghuo);
	printf("描述；%s\n",zongzhuangbei[zhuangbeirand4].zhuangbeimiaoshu); 
	printf("\n");
	printf("5.%s      %s\n",zongzhuangbei[zhuangbeirand5].zhungbeimingzi,zongzhuangbei[zhuangbeirand5].zhuangbeixianghuo);
	printf("描述；%s\n",zongzhuangbei[zhuangbeirand5].zhuangbeimiaoshu);
	printf("=====================================================================================================\n");
	printf("\n");
	printf("请输入数字购买装备，如无您想要的商品请按数字6\n");
	int f;
    f=dushuzi();
	if(f==1){
	if(xianghuo<zongzhuangbei[zhuangbeirand1].xiaohaoxianghuo){
	printf("你的米不够哦，宝子\n");
	}else{
			if(zongzhuangbei[zhuangbeirand1].js==0){
		printf("已售空\n");
		 }else{
    if(	zongzhuangbei[zhuangbeirand1].leixing==1){	
	zongzhuangbei[zhuangbeirand1].chiyou++;
	printf("物品已放入背包\n"); 

	}else{
		zhuangbeifenzhi(zongzhuangbei[zhuangbeirand1]);
		
	}
	zongzhuangbei[zhuangbeirand1].js=zongzhuangbei[zhuangbeirand1].js-1;
		xianghuo-=zongzhuangbei[zhuangbeirand1].xiaohaoxianghuo;
}
}
	}else if(f==2){	if(xianghuo<zongzhuangbei[zhuangbeirand2].xiaohaoxianghuo){
	printf("你的米不够哦，宝子\n");
	}else{
		if(zongzhuangbei[zhuangbeirand2].js==0){
		printf("已售空\n");
		 }else{
	 if(	zongzhuangbei[zhuangbeirand2].leixing==1){	
	zongzhuangbei[zhuangbeirand2].chiyou++;
		printf("物品已放入背包\n");
		
	}else{
			zhuangbeifenzhi(zongzhuangbei[zhuangbeirand2]);		
	}
		zongzhuangbei[zhuangbeirand2].js=zongzhuangbei[zhuangbeirand2].js-1;
		xianghuo-=zongzhuangbei[zhuangbeirand2].xiaohaoxianghuo;
}
}
	}else if(f==3){	if(xianghuo<zongzhuangbei[zhuangbeirand3].xiaohaoxianghuo){
	printf("你的米不够哦，宝子\n");
	}else{
	if(zongzhuangbei[zhuangbeirand3].js==0){
		printf("已售空\n");
		 }else{
	 if(	zongzhuangbei[zhuangbeirand3].leixing==1){	
	zongzhuangbei[zhuangbeirand3].chiyou++;
		printf("物品已放入背包\n");
		
	}else{
			zhuangbeifenzhi(zongzhuangbei[zhuangbeirand3]);
	}
		zongzhuangbei[zhuangbeirand3].js=zongzhuangbei[zhuangbeirand3].js-1;
			xianghuo-=zongzhuangbei[zhuangbeirand3].xiaohaoxianghuo;
}
}
	}else if(f==4){	if(xianghuo<zongzhuangbei[zhuangbeirand4].xiaohaoxianghuo){
	printf("你的米不够哦，宝子\n");
	}else{
	if(zongzhuangbei[zhuangbeirand4].js==0){
		printf("已售空\n");
		 }else{
	 if(	zongzhuangbei[zhuangbeirand4].leixing==1){	
	zongzhuangbei[zhuangbeirand4].chiyou++;
		printf("物品已放入背包\n");
	
	}else{
		zhuangbeifenzhi(zongzhuangbei[zhuangbeirand4]);
	
	}
	zongzhuangbei[zhuangbeirand4].js=zongzhuangbei[zhuangbeirand4].js-1;
		xianghuo-=zongzhuangbei[zhuangbeirand4].xiaohaoxianghuo;
	
} 
}
	}else if(f==5){	if(xianghuo<zongzhuangbei[zhuangbeirand5].xiaohaoxianghuo){
	printf("你的米不够哦，宝子\n");
	}else{
	if(zongzhuangbei[zhuangbeirand5].js==0){
		printf("已售空\n");
		 }else{

	 if(	zongzhuangbei[zhuangbeirand5].leixing==1){	
	zongzhuangbei[zhuangbeirand5].chiyou++;
	printf("物品已放入背包\n");

	}else{
		zhuangbeifenzhi(zongzhuangbei[zhuangbeirand5]);
	
	}
	zongzhuangbei[zhuangbeirand5].js=zongzhuangbei[zhuangbeirand5].js-1;
		xianghuo-=zongzhuangbei[zhuangbeirand5].xiaohaoxianghuo;
}
	}
	}else if(f==6){
	break; 
	}else {printf("宝子你不乘哦，请输入正确数字\n"); 
	} 

}while(1);
  
}
int beibao(){
	int youhuo[10];
	int o=0;
	printf("==============物品栏==============\n");
	for(int p=0; p<10; p++){
		if(zongzhuangbei[p].chiyou>0){
			youhuo[o]=p;
			o++;
		printf("%d. %s  持有%d\n",o,zongzhuangbei[p].zhungbeimingzi,zongzhuangbei[p].chiyou);
		
		}
	}
		if(o==0){
			printf("背包目前空空如也\n");
			return 0;
		}
	printf("请选择要使用的物品(按数字0返回)\n");
	int g;
     g=dushuzi();
	if(g>=1&&g<=o){
		int k=youhuo[g-1];
		zongzhuangbei[k].chiyou--; 
		if(zongzhuangbei[k].leixing==2){
			printf("您共造成了%d点伤害",zongzhuangbei[k].zhuangbei_atk);
			return zongzhuangbei[k].zhuangbei_atk;
		}else{zhuangbeifenzhi(zongzhuangbei[k]);
		return 0;
		}
		
	}
			
}







//事件池 
struct suijishijian{
	const char *wenben;
	const char *xuanxiang;
	int shijian1_hp;
	int shijian1_fangyu;
	int shijian1_gongji;
	int xianghuo1;
	int shijian2_hp;
	int shijian2_fangyu;
	int shijian2_gongji;
	int xianghuo2;
};

struct  suijishijian foxiang={"前台供着一尊佛像，佛手是个方向盘。「施主，往哪开？」","1.转：香火+15   2.拜：生命+10",0,0,0,15,10,0,0,0, 
};
struct  suijishijian laodaoshi={"工位旁的咖啡机吐出一杯泛绿光的液体，杯壁浮着一行小字：「道友，喝吗？」","1.接那杯绿的：生命-20 攻击+8   2.倒掉：生命+10",-20,0,8,0,10,0,0,0, 
};
struct  suijishijian dayin={"角落里的打印机卡纸处吐出一张纸，标题是《关于某位程序员猝死的通报》。","1.打印：香火+15 生命-10   2.拔电：HP+15",-10,0,0,15,15,0,0,0,
};
struct  suijishijian moyu={"旁边同事电脑屏幕右下角弹出「检测到摸鱼行为，是否继续？」","1.摸：生命+15 攻击+3    2.加班：香火+12 hp-8",15,0,3,0,-8,0,0,12,
};
struct  suijishijian jingzi={"你走到一个镜子前，镜子里的你，戴着猫耳。","1.照：生命+15 攻击-5  2.走开：防御+5",15,0,-5,0,0,5,0,0, 
};
struct  suijishijian wife={" 手机上的WiFi列表突然多出一个信号，满格。SSID 是「老祖的WiFi_5G」，没密码。","1.连上：整栋楼的噪音都退了下去，你的手指变得很稳。   2.不连：那个信号一直在转圈，「无法连接」。你越看越烦。",0,0,14,0,0,0,-5,0,
}; 
struct suijishijian wubug={"一段代码从你指间滑过，通体透明，没有一行是红的。","1.读完它：你盯着看了很久，忽然很想哭，但手指记住了它。   2.删掉它：世界不需要这种东西。删完你手有点抖。",0,0,12,0,20,10,0,0,
};
struct suijishijian gouqi={"抽屉最里层，一包没拆封的枸杞。生产日期是三年前，前任留下的。","1.泡了它：包装上有人用笔写着两个字：「保重。」   2.扔了它：垃圾桶里一声轻响，你忽然觉得有点冷。",30,5,0,0,0,0,-5,0,
};

/*屎山纪念，哈哈哈 
void shijian(struct suijishijian j){
	int s;
    if(s<20){printf("%s\n",j.wenben);
             printf("%s\n",j.xuanxiang);
             int sj1a;
             scanf("%d",&sj1a);
             if(sj1a==1){xianghuo+=j.xianghuo1;
			 }else if(sj1a==2){player_hpmax+=j.shijian2_hp;
			 player_hp+=j.shijian2_hp;
			 }else {printf("请输入1或2\n");
			 }
			 
	}
    else if(s<40){
    	printf("%s\n",j.wenben);
             printf("%s\n",j.xuanxiang);
             int sj1b;
             scanf("%d",&sj1b);
             if(sj1b==1){player_hpmax+=j.shijian1_hp;
			 player_hp+=j.shijian1_hp;
			 player_atk+=j.shijian1_gongji; 
			 }else if(sj1b==2){player_hpmax+=j.shijian2_hp;
			 player_hp+=j.shijian2_hp;
			 }else {printf("请输入1或2\n"); 
			 }
	}
	else if(s<60){
		printf("%s\n",j.wenben);
             printf("%s\n",j.xuanxiang);
             int sj1c;
             scanf("%d",&sj1c);
             if(sj1c==1){xianghuo+=j.xianghuo1;
             player_hpmax+=j.shijian1_hp;
			 player_hp+=j.shijian1_hp;
			 }else if(sj1c==2){player_hpmax+=j.shijian2_hp;
			 player_hp+=j.shijian2_hp;
			 }else {printf("请输入1或2\n"); 
			 }
	}
	else if(s<80){
		printf("%s\n",j.wenben);
             printf("%s\n",j.xuanxiang);
             int sj1d;
             scanf("%d",&sj1d);
             if(sj1d==1){player_hpmax+=j.shijian1_hp;
			 player_hp+=j.shijian1_hp;
			  player_atk+=j.shijian1_gongji; 
			 }else if(sj1d==2){player_hpmax+=j.shijian2_hp;
			 player_hp+=j.shijian2_hp;
			 }else {printf("请输入1或2\n");
			 }
	}
    else{
    	printf("%s\n",j.wenben);
             printf("%s\n",j.xuanxiang);
             int sj1e;
             scanf("%d",&sj1e);
             if(sj1e==1){player_hpmax+=j.shijian1_hp;
			 player_hp+=j.shijian1_hp;
			  player_atk+=j.shijian1_gongji; 
			 }else if(sj1e==2){player_def+=j.shijian2_fangyu; 
			 }else {printf("请输入1或2\n"); 
			 }
	}
}
*/ 



void shijian(struct suijishijian j){
	printf("%s\n",j.wenben);
	printf("%s\n",j.xuanxiang);
	int sj;
	  sj=dushuzi();
	if(sj==1){
	player_hpmax+=j.shijian1_hp;
	player_hp+=j.shijian1_hp;
	player_def+=j.shijian1_fangyu;
	player_atk+=j.shijian1_gongji;
	xianghuo+=j.xianghuo1;
		printf("     =================状态栏=================\n");	
	printf("程序员：生命:%d 防御：%d 攻击:%d 香火：%d\n",player_hp , player_def , player_atk,xianghuo);
	printf("\n");	
}else if(sj==2){
		player_hpmax+=j.shijian2_hp;
	player_hp+=j.shijian2_hp;
	player_def+=j.shijian2_fangyu;
	player_atk+=j.shijian2_gongji;
	xianghuo+=j.xianghuo2;	
		printf("     =================状态栏=================\n");
printf("程序员：生命:%d 防御：%d 攻击:%d 香火：%d\n",player_hp , player_def , player_atk,xianghuo);
	printf("\n");	
	}else {printf("请输入1或2\n"); 
		
		
	}	
}
	
	struct  suijishijian putongshijian[5]={foxiang,laodaoshi,dayin,moyu,jingzi,} ;
    struct  suijishijian qiyushijian[3]={wife,wubug, gouqi,};
	

//战斗 
void zhandou(struct guaiwu m){
		printf("%s",m.chuchangwenan);
		do{ 
			printf("     =================状态栏=================\n");
		printf("程序员：生命:%d 防御：%d 攻击:%d 香火：%d\n",player_hp , player_def , player_atk,xianghuo);
			printf("\n");	
	    printf("%s：生命:%d 防御：%d 攻击:%d\n",m.mingzi,m.m_hp , m.m_def , m.m_atk);
		printf("按1攻击  按2逃跑 按3打开背包\n");
		int c; 
		c=dushuzi();
		if(c==1){
//攻击代码			
		int dam =gongjidam(player_atk,m.m_def);	 
		if(dam>player_atk*3/10){printf("效果拔群！共造成%d点伤害\n",dam);
		m.m_hp-=dam; 
		}else {printf("效果差了点,但“原神 ”帮助你造成了%d点伤害\n",dam);
		m.m_hp-=dam ;
		
	}
		if(m.m_hp<0){m.m_hp=0;
		}		
	        printf("%s：生命:%d 防御：%d 攻击:%d\n",m.mingzi,m.m_hp , m.m_def , m.m_atk);
	     if(m.m_hp<=0){break;   
	  }
		int dam1=gongjidam(m.m_atk,player_def); 
		printf(m.gongjiwenan,dam1);	
		player_hp-=dam1;
		if(player_hp<=0){break;
		}
    }
//逃跑代码 
	     if(c==2) {
	      int rate =taopaoes(player_hpmax,player_hp);
	      int roll =rand()%100;
		  printf("您的逃跑概率是%d%%\n",rate);
		  printf("是否逃跑？(按1逃跑 按2攻击 按3打开背包)\n");
//逃跑分支1
		  int d;
		  d=dushuzi();
		  if(d==1){ 	
	      if(rate>roll){printf("跑路了，兄弟，跑路了\n"); 
		  taopaole=1;
		  break;

		  }else {printf("完，没跑掉（摸额头，略显尴尬的笑）\n");
		  } 
		printf(m.taopaoshibaiwenan,m.m_atk*5/10);	
		player_hp-=m.m_atk*5/10;
		if(player_hp<=0){break;
		 }
         }
//逃跑分支2  
         else if(d==2){
         	int dam =gongjidam(player_atk,m.m_def);	 
		if(dam>player_atk*3/10){printf("效果拔群！共造成%d点伤害\n",dam);
		m.m_hp-=dam; 
		}else {printf("效果差了点,但“原神 ”帮助你造成了%d点伤害\n",dam);
		m.m_hp-=dam ;
	}   if(m.m_hp<0){m.m_hp=0;
		}
		   printf("%s：生命:%d 防御：%d 攻击:%d\n",m.mingzi,m.m_hp, m.m_def , m.m_atk);
	     if(m.m_hp<=0){ break;   
	  }
		int dam1=gongjidam(m.m_atk,player_def); 
		printf(m.gongjiwenan,dam1);	
		player_hp-=dam1;
		if(player_hp<=0){break;
		}
			if(d==3){
					m.m_hp-=beibao();
		} 
	 
		
//输入错误		
		}else {
			if(d!=1&&d!=2&&d!=3){
        printf("oi，小鬼怎么不按套路出牌呢？\n");	
		} 
			
		 }
    }
//背包分支    
    	if(c==3){
    		m.m_hp-=beibao();
		} 
		
//输入错误
        if(c!=1&&c!=2&&c!=3){
        printf("oi，小鬼怎么不按套路出牌呢？\n");	
		} 
	}while(1);
	
	
}

void jieshupt1(struct guaiwu m ){
	    if(taopaole==0){
	if(player_hp>0){	printf("%s被程序员成功打败，哦耶！\n",m.mingzi);
     int upxianghuopt1=rand()%3+3;
     xianghuo+=upxianghuopt1; 
     printf("恭喜获得香火*%d\n",upxianghuopt1);
     printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
 }else if(taopaole==1){printf("哼哼，知道我定仙游的厉害了不，下次再见我必斩杀你！\n");
  printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);	
  taopaole=0;
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
	
} 

void jieshujy1(struct guaiwu m ){
	    if(taopaole==0){
	if(player_hp>0){	printf("%s被程序员成功打败，哦耶！\n",m.mingzi);
     int upxianghuojy1=rand()%5+3;
     xianghuo+=upxianghuojy1; 
     printf("恭喜获得香火*%d\n",upxianghuojy1);
     printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
 }else if(taopaole==1){printf("哼哼，知道我定仙游的厉害了不，下次再见我必斩杀你！\n"); 
  printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
    taopaole=0;
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
	
} 

void jieshusl1(struct guaiwu m ){
	    if(taopaole==0){
	if(player_hp>0){	printf("%s被程序员成功打败，哦耶！\n",m.mingzi);
     int upxianghuosl1=rand()%10+6;
     xianghuo+=upxianghuosl1; 
     printf("恭喜获得香火*%d\n",upxianghuosl1);
     printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
 }else if(taopaole==1){printf("哼哼，知道我定仙游的厉害了不，下次再见我必斩杀你！\n"); 
  printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
    taopaole=0;
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
	
} 


//地图制作 
//事件桶 
void shijiantong(int t){
	taopaole=0;
     if(t<65){   		
    int rollzj1zhandou=rand()%100;
    if (rollzj1zhandou<70){
    	printf("%d.普通战斗\n",xuanxiang); 
    int rollzjzhandou1pt=rand()%100;
		if(rollzjzhandou1pt>=49){
		zhandou(ma1);
		jieshupt1(ma1); 
		xuanxiang++;
		guanqia++;
	}else {
    zhandou(mb1);
    jieshupt1(mb1);
    xuanxiang++;
    guanqia++;
}}
    else	{
   printf("%d.困难战斗\n",xuanxiang);
	int rollzjzhandou1jy=rand()%100; 
		if(rollzjzhandou1jy>=49){
		zhandou(mc1);
		jieshujy1(mc1);
		xuanxiang++;
		guanqia++;
		
	}else{
		zhandou(md1);
		jieshupt1(md1); 
		xuanxiang++;
		guanqia++;
	}	
}
}   
    else if(t>=65&&t<85){
	
		printf("%d.随机事件\n",xuanxiang);
		int shijianrand1;
		shijianrand1=rand()%5;
		shijian(putongshijian[shijianrand1]);
		xuanxiang++;
		guanqia++;		
	}
    else if(t<93){
	
	printf("%d.？？？\n",xuanxiang); 
	printf("                                                                        奇遇(谨慎选择,数值加强)\n");
	printf("\n");
	int shijianrand2=rand()%3;
	shijian(qiyushijian[shijianrand2]); 
	xuanxiang++;
	guanqia++;	
}
 else{
	printf("赛博货摊");
	shangdian();
	xuanxiang++;
	guanqia++;	
}
	 
}

const char*shijianming(int t){
	if(t<65){
		return "战斗事件";
	}if(t<85){
		return "随机事件"; 
	}if(t<93){
		return "？？？"; 
	}else{
		return"赛博货摊"; 
	} 
		
}


void ditu1 (){
	do{
	
	int t1=rand()%100;
	int t2=rand()%100;
	int t3=rand()%100; 
    printf("请输入1. 2. 3.选择事件\n");
    printf(" 1.%s 2.%s 3.%s\n",shijianming(t1),shijianming(t2),shijianming(t3));
	int e;
	e=dushuzi();
	if(e==1){shijiantong(t1);
	} 
     else if(e==2){shijiantong(t2);
	}
     else if(e==3){shijiantong(t3); 
	}
    else{
    printf("请输入1. 2. 3.\n");	
	}if(player_hp<=0){printf("程序员小高将再度踏上轮回…………\n");
}
}while(guanqia<9&&player_hp>0);
    
    if (player_hp>0){
    printf("    !---!---!---boss战来袭---!---!---!\n"); 
    zhandou(me1);
    jieshusl1(me1);
    printf("\n");
    printf("经过一番激烈的战斗，成功你借过了代码夜叉。\n"); 
    printf("？？？\n");
    printf("不对吧，结束了吗，这玩意也不像貔貅啊？？？\n"); 
    printf("（远处传来声音，小子过来，让我先开业）\n");
    printf("？？？，虽然你很蒙，但还是走了过去\n");
    printf("在你眼前的是一个衣衫褴褛的老者，他穿着斗篷，看不清脸\n");
	printf("【神秘老者】先看看有什么需要的吧，希望你可以挺过下一关\n"); 
    shangdian(); 
    printf("逛完他的货摊，你刚想说什么，老者身形便渐渐模糊直到消失不见\n");
    printf("你听见天空中传来刺耳的尖叫声，随后消失\n");
    printf("【黑影】哼，老不死的玩意，这次你也是徒劳，世界代码化一定会实现! 而你只不过是个失败者!!!\n");
    printf("【黑影】小子，你知道吗，曾经有很多自诩主角的人,也都打败过打败代码夜叉…………（空中传来不屑的声音）\n");
    printf("主角？谁？我……我吗？\n");
    printf("【黑影】哼，这次也不过是浮游撼树…………\n");
    printf("声音消失不见，只留下在空地上的小高\n");
    printf("玩我呢？？？这俩在说什么胡话，我想真该睡觉了\n"); 
    printf("\n");
    printf("第一章（完）");

}   
}




int main()
{ 
srand(time(0));
    printf("                                                                         ————欸，本猿也要飞升吗？？————\n");
    printf("按1继续游戏\n");
    dushuzi();
    printf("公元2026年，深夜12点30分……\n");
    printf("一名刚入社会的清纯大学生程序员，还在公司里苦命的敲着代码……\n");
    printf("也够老板，第21版了代码了，这次还不行我就(╯°□°）╯︵ ┻━┻\n");
	printf("发送代码至AAA程序批发商龙傲天\n"); 
	printf("………………额，小高啊，这个代码啊，我看还是第一版比较符合客户的需求，把第一版发给我吧\n"); 
    printf("你TM！！！！！（神怒），也够老板我c你老冯的(砸桌子)\n");
	printf("猛地，灯光闪烁，天地晃动，小高眼前一黑,片刻间光芒四射，一个男人从天而降\n"); 
	printf("? ? ? ? ? ?(猛男疑惑)这男的是谁啊，搞什么鬼？cosplay吗？？？这也不是图灵派的啊，我chovy，那我缺的南梁上哪给我补回来啊（没错程序员小高仅仅用0.1秒就接受了辣个男人从天而降的事实）\n"); 
    printf("oi,你是谁，要干什么？\n"); 
    printf("男人看着小高用着充满磁性的声音说：我是这方天地的一尊神明，这次唤你来是为了解决恶兽全栈——业火貔貅的污染问题，加油吧，骚年，kskbl,我要去看他直播了（欻，猛男起飞，猛男消失……，）\n"); 
    printf("???我？就我一个？？？我非去不可吗？？？（然而并没有人回应呆在原地的小高）\n"); 
    printf("按1继续游戏\n");
	
    dushuzi();
     player_hp=50;
     player_hpmax=50;
	 player_def=10;
	 player_atk=20;
	 xianghuo=0;	
	
	printf("欢迎来到赛博世界，您的初始数值为：");
	printf("生命:%d 防御：%d 攻击:%d\n",player_hp , player_def , player_atk);
	printf("你看了看周围，发现手边有两的物品可以选择，但只能选择其中一个（别问为什么，作者让的）\n");
	printf("按1选择键盘 防御+10 攻击+10\n");
	printf("按2选择显示屏 生命+20 防御+15\n"); 
	
	int b; 
	b=dushuzi();
	if(b==1){player_def+=10 ;player_atk+=10;
	}else if(b==2){player_hp+=20; player_def+=15; player_hpmax+=20;
	} else {printf("请输入1或者2\n");
	}
	printf("你感觉浑身充满了力量！！！power！！！\n");
		printf("     =================状态栏=================\n");
	printf("生命:%d 防御：%d 攻击:%d\n",player_hp , player_def , player_atk);
		printf("\n");	
	
	int monster1_hp=50;
	int monster1_def=5;
	int monster1_atk=10;
	printf("你看到一堆乱码，在空中缓慢凝聚成实体————缓存饿鬼出现了！\n");
	
	do{
		printf("     =================状态栏=================\n");
		printf("程序员：生命:%d 防御：%d 攻击:%d\n",player_hp , player_def , player_atk);
			printf("\n");	
	    printf("缓存饿鬼：生命:%d 防御：%d 攻击:%d\n",monster1_hp , monster1_def , monster1_atk);
		printf("按1攻击  按2逃跑\n");
		int c; 
	  c=dushuzi();
		if(c==1){
			
		int dam =gongjidam(player_atk,monster1_def);	 
		if(dam>player_atk*3/10){printf("效果拔群！共造成%d点伤害\n",dam);
		monster1_hp-=dam; 
		}else {printf("效果差了点,但“原神 ”帮助你造成了%d点伤害\n",dam);
		monster1_hp-=dam ;
	}
		if( monster1_hp<=0){ monster1_hp=0;
		}		
	        printf("缓存饿鬼：生命:%d 防御：%d 攻击:%d\n",monster1_hp , monster1_def , monster1_atk);
	     if(monster1_hp<=0){ break;   
	  }
		int dam1=gongjidam(monster1_atk,player_def); 
		printf("缓存饿鬼伸手将手臂代码化，数不清的代码进入了你的身体,共造成了%d点伤害\n",dam1);	
		player_hp-=dam1;
		if(player_hp<=0){break;
		}
    }

	     if(c==2) {
	      int rate =taopaoes(player_hpmax,player_hp);
	      int roll =rand()%100;
		  printf("您的逃跑概率是%d%%\n",rate);
		  printf("是否逃跑？(按1逃跑 按2攻击)\n");

		  int d;
		   d=dushuzi();
		  if(d==1){ 	
	      if(rate>roll){printf("跑路了，兄弟，跑路了\n"); 
		  taopaole=1;
		  break;

		  }else {printf("完，没跑掉（摸额头，略显尴尬的笑）\n");
		  } 
		printf("缓存饿鬼伸手将手臂代码化，一把抓住你的腿，顷刻炼化,共造成了%d点伤害\n",monster1_atk*5/10);	
		player_hp-=monster1_atk*5/10;
		if(player_hp<=0){break;
		 }
         }
  
         else if(d==2){
         	int dam =gongjidam(player_atk,monster1_def);	 
		if(dam>player_atk*3/10){printf("效果拔群！共造成%d点伤害\n",dam);
		monster1_hp-=dam; 
		}else {printf("效果差了点,但“原神 ”帮助你造成了%d点伤害\n",dam);
		monster1_hp-=dam ;
	}
		if( monster1_hp<=0){ monster1_hp=0;
		}
	        printf("缓存饿鬼：生命:%d 防御：%d 攻击:%d\n",monster1_hp , monster1_def , monster1_atk);
	     if(monster1_hp<=0){ break;   
	  }
		int dam1=gongjidam(monster1_atk,player_def); 
		printf("缓存饿鬼伸手将手臂代码化，数不清的代码进入了你的身体,共造成了%d点伤害\n",dam1);	
		player_hp-=dam1;
		if(player_hp<=0){break;
		}
		
		}else {
			if(d!=1&&d!=2){
        printf("oi，小鬼怎么不按套路出牌呢？\n");	
		} 
			
		 }
    }

        if(c!=1&&c!=2){
        printf("oi，小鬼怎么不按套路出牌呢？\n");	
		} 
	}while(1);
//完成战斗	
    if(taopaole==0){
	if(player_hp>0){	printf("缓存饿鬼被程序员成功打败，哦耶！\n");
     int upxianghuo=rand()%3+3;
     xianghuo+=upxianghuo; 
     printf("恭喜获得香火*%d\n",upxianghuo);
     	printf("     =================状态栏=================\n");
     printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
     	printf("\n");	
     ditu1();
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}
 }else if(taopaole==1){printf("哼哼，知道我定仙游的厉害了不，下次再见我必斩杀你！\n"); 
  printf("生命:%d 防御：%d 攻击:%d 香火%d\n",player_hp , player_def , player_atk,xianghuo);
  	printf("\n");	
  ditu1();
	}else{printf("程序员小高将再度踏上轮回…………\n");
	}




}
 
		  
		
		
		
				
		

