int getfrq(char chr)
{
    switch (chr) {
                case 'c': return 523; 
                case 'd': return 587;
                case 'e': return 659;
                case 'f': return 698;
                case 'g': return 783;
                case 'a': return 880;
                case 'b': return 983; 
                case 'C': return 1047;
                case 'D': return 1174;
                case 'E': return 1318;
                case 'F': return 1396;
                case 'G': return 1568;
                case 'A': return 1760;
                case 'B': return 1975;

                default: return -1;
            }
}