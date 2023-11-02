#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {
public:
    emp::web::Canvas canvas{500, 500, "canvas"};

    NFAnimator() {
        doc << canvas;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                canvas.Rect(i * 50, j * 50, 50, 50, "white", "black");
            }
        }
    }
    void FindNeighbor(int x, int y) {
        
        canvas.Rect(x, y, 50, 50, "black", "black");
        if(y+50 < 500) {
            canvas.Rect(x, y+50, 50, 50, "red", "black");
        }
        if(x+50 < 500) {
            canvas.Rect(x+50, y, 50, 50, "red", "black");
        }
        if(x-50 > 0){
            canvas.Rect(x-50, y, 50, 50, "red", "black");
        }
        if(y-50 > 0) {
            canvas.Rect(x, y-50, 50, 50, "red", "black");
        }
        
    }
    
};

NFAnimator animator;

int main()
{
    animator.Step();
    animator.FindNeighbor(200, 200);
    animator.FindNeighbor(0, 200);
    animator.FindNeighbor(200, 0);
    animator.FindNeighbor(400, 300);
    animator.FindNeighbor(200, 400);
    animator.FindNeighbor(300, 0);
}
