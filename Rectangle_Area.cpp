/*
   Find the total area covered by two rectilinear rectangles in a 2D plane.

   Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 */

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      // two areas
      int sum = (C - A) * (D - B) + (G - E) * (H - F);
      // overlap region
      int xlow = max(A, E);
      int xhigh = min(C, G);
      int ylow = max(B, F);
      int yhigh = min(D, H);
      // length of overlap
      int x = (xhigh > xlow) ? xhigh - xlow : 0; // 整形溢出
      int y = (yhigh > ylow) ? yhigh - ylow : 0;

      return sum - x * y;
    }
};
