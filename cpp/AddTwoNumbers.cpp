/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 結果の連結リストのダミーノードを作成
        ListNode* sumListNode = new ListNode(0);
        // 現在のノードを指し示すポインタ
        ListNode* current = sumListNode;

        // 繰り上げ変数
        int carryUp = 0;

        // l1とl2の各ノードについて処理
        while (l1 != nullptr && l2 != nullptr) {
            // l1とl2の対応する桁の値を取得
            int x1 = l1->val;
            int x2 = l2->val;
            // 繰り上げとx1, x2を加算
            int sum = carryUp + x1 + x2;
            // 新しいノードの値
            int y = sum % 10;
            // 繰り上げの更新
            carryUp = sum / 10;

            // 新しいノードを作成し、currentのnextに設定
            current->next = new ListNode(y);
            // currentを次のノードに移動
            current = current->next;
            // 次の桁へ進む
            l1 = l1->next;
            l2 = l2->next;
        }

        // l1の残りの桁について処理
        while (l1 != nullptr) {
            int x1 = l1->val;
            int sum = carryUp + x1;
            int y = sum % 10;
            carryUp = sum / 10;
            current->next = new ListNode(y);
            current = current->next;
            l1 = l1->next;
        }

        // l2の残りの桁について処理
        while (l2 != nullptr) {
            int x2 = l2->val;
            int sum = carryUp + x2;
            int y = sum % 10;
            carryUp = sum / 10;
            current->next = new ListNode(y);
            current = current->next;
            l2 = l2->next;
        }

        // 最終的な繰り上げがあれば、新しいノードを追加
        if (carryUp != 0) {
            current->next = new ListNode(carryUp);
        }

        // ダミーノードをスキップして次のノードを返す
        return sumListNode->next;
    }
};
