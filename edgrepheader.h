#define	BLKSIZE	4096
#define	NBLK	2047
#define	FNSIZE	128
#define	LBSIZE	4096
#define	ESIZE	256
#define	GBSIZE	256
#define	NBRA	5
#define	KSIZE	9
#define	CBRA	1
#define	CCHR	2
#define	CDOT	4
#define	CCL	6
#define	NCCL	8
#define	CDOL	10
#define	CEOF	11
#define	CKET	12
#define	CBACK	14
#define	CCIRC	15
#define	STAR	01
#define	READ	0
#define	WRITE	1

char *getblock(unsigned int atl, int iof);
char *_getline(unsigned int tl);
int advance(char *lp, char *ep);
int append(int (*f)(void), unsigned int *a);
int backref(int i, char *lp);
void blkio(int b, char *buf, ssize_t (*iofcn)(int, const void*, size_t)); //int(*) (int, char*, int)
void rblkio(int b, char *buf, ssize_t (*iofcn)(int, void*, size_t));
int cclass(char *set, int c, int af);
void commands(void);
void compile(int eof);
void error(char *s);
int execute(unsigned int *addr);
void exfile(void);
void filename(int comm);
int getchr(void);
int getfile(void);
int getnum(void);
void global(int k);
void init(void);
unsigned int *address(void);
void newline(void);
void nonzero(void);
void onhup(int n);
void onintr(int n);
void print(void);
void putchr(int ac);
void putd(void);
void putfile(void);
int putline(void);
void quit(int n);
void setwide(void);
void setnoaddr(void);
void squeeze(int i);
void grepline(void); char grepbuf[GBSIZE]; void greperror(char);

char	Q[]	= "";
char	T[]	= "TMP";
int peekc; int lastc; char savedfile[FNSIZE]; char file[FNSIZE]; char linebuf[LBSIZE]; char rhsbuf[LBSIZE/2];
char expbuf[ESIZE+4]; int given; unsigned int *addr1, *addr2; unsigned int *dot, *dol, *zero; char genbuf[LBSIZE];

long count; 
char *nextip; 
char *linebp; 
int ninbuf; int	io; int pflag; long lseek(int, long, int);
int open(char *, int); int creat(char *, int); int close(int); int fork(void); int wait(int *);
int vflag	= 1; int oflag; int listf; int listn; int col; char *globp; int	tfile = -1;
int tline; char	*tfname; char *loc1; char *loc2; char ibuff[BLKSIZE]; int iblock = -1;
char obuff[BLKSIZE]; int oblock	= -1; int ichanged; int	nleft; char WRERR[] = "WRITE ERROR";
int names[26]; char *braslist[NBRA]; char *braelist[NBRA]; int nbra; int fchange; int bpagesize = 20; unsigned nlall = 128;

char	tmpXXXXX[50] = "/tmp/eXXXXX";

jmp_buf	savej;
char	line[70]; char	*linp	= line;
void cerror(void);

typedef void	(*SIG_TYP)(int);
SIG_TYP	oldhup; SIG_TYP	oldquit; /* these two are not in ansi, but we need them */
#define	SIGHUP	1	/* hangup */
#define	SIGQUIT	3	/* quit (ASCII FS) */
