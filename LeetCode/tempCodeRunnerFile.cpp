        if (x < y) {
            reverse(s.begin(), s.end());
            return maximumGain(s, y, x);
        }