#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


int main(int argc, char **argv)
{
    int msgid, rc, msg_length;
    struct msqid_ds buf;

    msgid = msgget((key_t)987, IPC_CREAT|0666);
    if (msgid < 0)
    {
        perror("Get message ID error.");
        return -1;
    }

    rc = msgctl(msgid, IPC_STAT, &buf);
    if (rc < 0)
    {
        perror("Read message status error.");
        return -1;
    }

    printf("[MSGID %d IPC_STAT] gid: %d\n", msgid, buf.msg_perm.gid);
    printf("[MSGID %d IPC_STAT] uid: %d\n", msgid, buf.msg_perm.uid);
    printf("[MSGID %d IPC_STAT] mode: %d\n", msgid, buf.msg_perm.mode);
    printf("[MSGID %d IPC_STAT] size: %ld\n", msgid, buf.msg_qbytes);

    rc = msgctl(msgid, IPC_RMID, 0);
    if (rc < 0)
    {
        perror("RM message ID error.");
        return -1;
    }

    return 0;
}

