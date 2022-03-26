

int countOdds(int low, int high){
    if (low % 2 == 0) {
        return (high - low + 1) / 2;
    }
    return (high - low) / 2 + 1;
}
