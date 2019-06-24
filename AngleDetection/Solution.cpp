bool IsInRightPlace(AActor* ActorToCompareWith)  
{  
    if (ActorToCompareWith == nullptr)  
    {  
        UE_LOG(Log, Error, TEXT("The actor to compare with is missing "))  
        return false;  
    }  
  
    if (ActorToCompareWith->IsPlaced())  
    {  
        return false;  
    }  
  
  
    //Check if the actor is too far  
    const float DistanceSquared = FVector::DistSquared(GetActorLocation(), ActorToCompareWith->GetActorLocation());  
    if (DistanceSquared > DistanceDetectionToleranceSquared)  
    {  
        return false;  
    }  
  
    //Check if the alignment is different  
    const FVector AToCompareWithNormalizedeVector = ActorToCompareWith->GetActorForwardVector().GetSafeNormal2D();  
    const FVector CurrentActorNormalizedVector = GetActorForwardVector().GetSafeNormal2D();  
    const float DotProduct = FVector::DotProduct(AToCompareWithNormalizedeVector , CurrentActorNormalizedVector );  
  
    float AngleDifference = FMath::RadiansToDegrees(FMath::Acos(DotProduct ));  
    if (AngleDifference > 90.0f && bActorIsSymmetrical)  
    {  
        AngleDifference = FMath::Abs(AngleDifference - 180.0f);  
    }  
  
    if (AngleDifference > AngleDetectionTolerance)  
    {  
        return false;  
    }  
  
    return true;  
}  