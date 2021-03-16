int checksum(unsigned short *packet, int size) {
    int sum = 0;
    unsigned short *p = packet;
    unsigned short result = 0;

    while (size > 1) {
        sum += *p++;
        size -= 2;
    }

    if (size == 1) {
        *(unsigned char *) (&result) = *(unsigned char *) p;
        sum += result;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}
