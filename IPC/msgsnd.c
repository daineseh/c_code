#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


typedef struct mymsg {
    long int    mtype;       /* message type */
    char        mtext[128];    /* message text */
} msgbuf;

int main(int argc, char **argv)
{
    int msgid, ret, msg_length;
    msgbuf buf;

    msgid = msgget((key_t)987, IPC_CREAT|0666);
    if (msgid < 0)
    {
        perror("Get message ID error.");
        return -1;
    }

    strcpy(buf.mtext, "TEST[1]");
    buf.mtype = 1;
    msg_length = sizeof(msgbuf) - sizeof(long int);
    ret = msgsnd(msgid, &buf, msg_length, IPC_NOWAIT);
    if (ret < 0)
    {
        perror("Send message error.");
    }

    return 0;
}

