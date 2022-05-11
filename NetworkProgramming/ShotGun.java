interface Reload {
    public void reloadBullet();
}

interface Shoot {
    public void consumeBullet();
}

class Gun {
    String name;
    int bullet;

    void statusGun() {
        System.out.println("Gun name: " + name);
        System.out.println("Remain bullet: " + bullet);
        System.out.println();
    }
}

public class ShotGun extends Gun implements Reload, Shoot {
    public ShotGun(String gunName) {
        name = gunName;
        bullet = 8;
        System.out.println("Create Shotgun");
    }

    public void consumeBullet() {
        bullet -= 1;
        System.out.println("Shoot!");
    }


    public void reloadBullet() {
        bullet = 8;
        System.out.println("Reload Bullet...");
    }

    public void propertyDisplay() {
        consumeBullet();
        statusGun();

        reloadBullet();
        statusGun();

        System.out.println("==== End Status ====");
    }

    public static void main(String args[]) {
        try {
            ShotGun shotGun = new ShotGun(args[0]);
            shotGun.propertyDisplay();
        }
        catch (java.lang.ArrayIndexOutOfBoundsException error) {
            System.out.println("usage: java ShotGun GunName");
        }
    }
}
