class Robot {

        int width;
        int height;
        int[] pos;
        String dir;
        int x;
        int y;
        int perimiter;
        public Robot(int width, int height) {
            this.width = width;
            this.height = height;
            this.x = 0;
            this.y = 0;
            this.dir = "East";
            this.perimiter = (width-1)*2 + (height-1)*2;
        }

        public void move(int num) {
            int delta;
            if (num == 0) {
                return;
            }
            if (this.perimiter > 0)
                num = num % this.perimiter;
            while (num > 0) {
                if (this.dir.equals("East")) {
                    if (x + 1 < width) {
                        delta = Math.min(num, width - x - 1);
                        x += delta;
                        num -= delta;
                    }
                    else {
                        this.dir = "North";
                    }
                }
                else if (this.dir.equals("North")) {
                    if (y + 1 < height) {
                        delta = Math.min(num, height - y - 1);
                        y += delta;
                        num -= delta;
                    }
                    else {
                        this.dir = "West";
                    }
                }
                else if (this.dir.equals("West")) {
                    if (x - 1 >= 0) {
                        delta = Math.min(num, x);
                        x -= delta;
                        num -= delta;
                    }
                    else {
                        this.dir = "South";
                    }

                }
                else if (this.dir.equals("South")) {
                    if (y - 1 >= 0) {
                        delta = Math.min(num, y);
                        y -= delta;
                        num -= delta;
                    }
                    else {
                        this.dir = "East";
                    }
                }
            }
            if (x == 0 && y == 0) {
                this.dir = "South";
            }
            else if (y == 0 && x ==  width - 1) {
                this.dir = "East";
            }
            else if (x == width - 1 && y == height - 1) {
                this.dir = "North";
            }
            else if (x == 0 && y == height - 1) {
                this.dir = "West";
            }
        }

        public int[] getPos() {
            return new int[]{this.x, this.y};
        }

        public String getDir() {
            return this.dir;
        }
    }

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.move(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */
