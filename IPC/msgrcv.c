#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

typedef struct mymsg {
    long int    mtype;     /* message type */
    char        mtext[128];  /* message text */
} msgbuf;

int main(int argc, char **argv)
{
    int msgid, rc, msg_length;
    msgbuf buf;
    memset(&buf, '\0', sizeof(msgbuf));

    msgid = msgget((key_t)987, IPC_CREAT|0666);
    if (msgid < 0)
    {
        perror("Get message ID error.");
        return -1;
    }

    msg_length = sizeof(msgbuf) - sizeof(long int);
    rc = msgrcv(msgid, &buf, msg_length, 1, IPC_NOWAIT);
    if (rc < 0)
    {
        perror("Receive message error.");
        return -1;
    }
    printf("[MSGRCV] %s\n", buf.mtext);

    return 0;
}
