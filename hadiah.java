import java.math.BigInteger;
import java.util.Scanner;
public class hadiah{
    //driver
    

    static BigInteger powers(BigInteger num, long p){
        if (p == 0){
            return new BigInteger("1");
        }
        BigInteger two = new BigInteger("2");
        BigInteger one = new BigInteger("1");
         
        BigInteger res = new BigInteger("1");
        BigInteger pow = num;
        while (p > 0){
            if (p % 2 == 1) res = res.multiply(pow);
            p = p >> 1;
            pow = pow.multiply(pow);
        }
        return res;
    }

    static long powerMod(long num, BigInteger p, long mod){
        if (p.compareTo(BigInteger.valueOf(0)) == 0){
            return 1;
        }
        BigInteger two = new BigInteger("2");
        BigInteger one = new BigInteger("1");

        long res = 1;
        long pow = num;
        
         while (p.compareTo(BigInteger.valueOf(0)) > 0){
            if (p.mod(two).compareTo(one) == 0) res = (res * (pow % mod)) % mod;
            p = p.shiftRight(1);
            pow = (pow * pow) % mod;
         }
         return res;
    }

    public static void main(String srg[]){
        Scanner in = new Scanner(System.in);
        String s[] = in.nextLine().split(" ");

        long a = Long.parseLong(s[0]);
        BigInteger b = new BigInteger(s[1]);
        long c = Long.parseLong(s[2]);

        long n = Long.parseLong(s[3]);
        // BigInteger res = power(a, b);
        BigInteger res2 = powers(b, c);
        // System.out.println(res2);

        long res = powerMod(a, res2, n) + 1;
        // String result = res.toString(10);
        System.out.println(res);
        // String name = in.nextLine();
        // System.out.println(name);
    }
}