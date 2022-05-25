// #include "sources/OrgChart.hpp"
// using namespace std;
// using namespace ariel;
// #include "queue"

// int main(int argc, char const *argv[])
// {
//   OrgChart organization;
//   organization.add_root("CEO")
//       .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
//       .add_sub("CEO", "CFO")      // Now the CFO is subordinate to the CEO
//       .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
//       .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
//       .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

    

//     // for(auto it = organization.begin_reverse_order();it!=organization.reverse_order();++it){
//     //     cout << *it << " ";
//     // }

    
//     OrgChart ss(organization);
//     cout << ss;
//     // org.add_sub("tal", "renana");



// // auto it = organization.begin_preorder();
// // cout << *it;

// // CEO
// //        |--------|--------|
// //        CTO      CFO      COO
// //        |                 |
// //        VP_SW             VP_BI
// //  */

// //  
// //vp_bi vp sw cto cfo coo ceo
// //

// //   for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
// //   {
// //     cout << (*it) << " " ;
// //   }
// //   cout <<endl;
// //   cout << organization;
  
//    // prints: CEO CTO CFO COO VP_SW VP_BI
// //   for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
// //   {
// //     cout << (*it) << " " ;
// //   } // prints: VP_SW VP_BI CTO CFO COO CEO
// //   for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
// //     cout << (*it) << " " ;
// //   }  // prints: CEO CTO VP_SW CFO COO VP_BI

// // auto it = organization.begin_level_order();
// // cout << *it;



    

    

 




//     }
